#include "calculator.h"

calculator::calculator(QObject *parent = 0) : QThread(parent)
{
abort = false;
init_gen_rand(QDateTime::currentDateTime().toTime_t());
}

calculator::~calculator()
{
}

void calculator::abortCalculation()
{
abort = true;
}

void calculator::run()
{
abort = false;
if( (mprec == 0) | (mpar == 0) )
    return;
qDebug() << "Parameter" << mpar << "Precision" << mprec << "Mode" << mmode;

mp::mp_init(mprec+2);
mp::mpsetprec(mprec);
mp::mpsetoutputprec(mprec);

time.start();

switch( mmode ) {
    case montecarlo : {
                      mpar = pow(10, mpar);
                      quint64 walk = mpar/1000;
                      quint64 hits = 0;
                      double x,y;
                      if( walk == 0 ) walk = 1;
                      for(quint64 current=1;current<=mpar;current++) {
                          x=genrand_real3();
                          y=genrand_real3();
                          if( x*x+y*y <= 1 )
                              hits++;
                          if( current % walk == 0 )
                              emit update(1000*current/mpar);
                          if( abort )
                              break;
                      }
                      mp_real pi = mp_real(hits)/mp_real(mpar)*4;
                      mresult = QString::fromStdString(pi.to_string());
                      break;
                      }
    case montemin1 : {
                      mpar = pow(10, mpar)-1;
                      quint64 walk = mpar/1000;
                      quint64 hits = 0;
                      double x,y;
                      if( walk == 0 ) walk = 1;
                      for(quint64 current=1;current<=mpar;current++) {
                          x=genrand_real3();
                          y=genrand_real3();
                          if( x*x+y*y <= 1 )
                              hits++;
                          if( current % walk == 0 )
                              emit update(1000*current/mpar);
                          if( abort )
                              break;
                      }
                      mp_real pi = mp_real(hits)/mp_real(mpar)*4;
                      mresult = QString::fromStdString(pi.to_string());
                      break;
                      }
    case subdivide : {
                     mp_real x, a;
                     mpar = pow(10, mpar);
                     quint64 walk = mpar/1000;
                     quint64 current = 0;
                     a=0;
                     mp_real real_par(mpar);
                     x=1/(real_par*0.5);
                     while( x < 1 ) {
                         current++;
                         a+=1*sqrt(1-(x*x))/real_par;
                         x+=(1/real_par);
                         if( current % walk == 0)
                             emit update(current/walk);
                         if( abort )
                             break;
                         }
                     mp_real pi = a*4;
                     mresult = QString::fromStdString(pi.to_string());
                     break;
                     }
    case grid : {
                quint64 res = pow(10, mpar);
                quint32 walk = res/1000+1;
                quint64 hits = 0;
                quint64 x = 0, y = res;
                while( y > 0 )
                {
                    while( x*x+y*y <= res )
                        x++;
                    hits += x;
                    if( y % walk == 0 ) emit update((res-y)/(walk+1));
                    y--;
                    if( abort )
                        break;
                }
                mp_real pi = mp_real(hits)/mp_real(res)*4;
                mresult = QString::fromStdString(pi.to_string());
                break;
                }
    case bbp : {
                mp_real pi;
                for(quint32 step=0;step<=mpar;step++) {
                    pi += ((mp_real(4)/mp_real(8*step+1))-(mp_real(2)/mp_real(8*step+4))-(mp_real(1)/mp_real(8*step+5))-(mp_real(1)/mp_real(8*step+6)))/(pow(mp_real(16),(int)step));
                    emit update(1000*step/mpar);
                    if( abort )
                        break;
                    }
                mresult = QString::fromStdString(pi.to_string());
                break;
                }
    case chudnovsky : {
                mp_real temp;
                for(quint32 step=0;step<=mpar;step++) {
                    mp_real upper = fak(6*step)*(13591409+545140134*mp_real(step))*pow(-1,step);
                    mp_real lower = pow(640320,mp_real(3*step)+1.5)*(fak(3*step)*pow(fak(step),3)+0.0);
                    temp += upper/lower;
                    emit update(1000*step/mpar);
                    if( abort )
                        break;
                    }
                mp_real pi = mp_real(1)/(temp*12);
                mresult = QString::fromStdString(pi.to_string());
                break;
                }
    case polygon : {
                mp_real pi_min = mp_real(mpar)/2*sin(2*mp_real::_pi/mp_real(mpar));
                mp_real pi_max = mp_real(mpar)*tan(mp_real::_pi/mp_real(mpar));
                mp_real pi_mid = (pi_min+pi_max)/2;
                mresult = QString::fromStdString(pi_min.to_string())+" < Pi < "+QString::fromStdString(pi_max.to_string()) +"\nPi = "+QString::fromStdString(pi_mid.to_string());
                break;
                }
}

duration = time.elapsed();



mp::mp_finalize();
}

QString calculator::result()
{
return mresult;
}

void calculator::setMode(mode calcmode)
{
mmode = calcmode;
}

void calculator::setParameter(quint32 parameter)
{
mpar = parameter;
}

mp_int calculator::fak(quint64 value)
{
mp_int ms(1);
for(;value>0;value--)
    ms *= value;
return(ms);
}

void calculator::setPrecision(quint32 precision)
{
mprec = precision+1;
}
