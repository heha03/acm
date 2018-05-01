package RSA;

import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.Random;
class Utils {

    private static Random ran=null;

    static{
        ran=new SecureRandom();
    }

    /**
     * 计算 base^exp % n
     */
    private static BigInteger expmod(int base,BigInteger exp,BigInteger n){
        if(exp.equals(BigInteger.ZERO)){
            return BigInteger.ONE;
        }
        if(!exp.testBit(0)){//如果为偶数
            return expmod(base,exp.divide(BigInteger.valueOf(2)),n).pow(2).remainder(n);
        } else{
            return(expmod(base,exp.subtract(BigInteger.ONE).divide(BigInteger.valueOf(2)),n).pow(2).multiply(BigInteger.valueOf(base))).remainder(n);
        }
    }

    /**
     * Miller-Rabin测试
     */
    private static boolean passesMillerRabin(BigInteger n){
        BigInteger thisMinusOne=n.subtract(BigInteger.ONE);
        BigInteger m=thisMinusOne;
        int k=0;
        while(!m.testBit(0)){
            m=m.shiftRight(1);k++;
        }
        //随机选择a
        int a= 1;
        if(n.compareTo(BigInteger.valueOf(Integer.MAX_VALUE))<0){
            a=ran.nextInt(n.intValue()-1)+1;
        } else{
            a=ran.nextInt(Integer.MAX_VALUE-1)+1;
        }

        BigInteger b=expmod(a,m,n);
        if(b.equals(BigInteger.ONE))return true;
        for(int i=0;i<k-1;i++){
            if(b.equals(thisMinusOne)){
                break;
            } else{
            	b=b.multiply(b).mod(n);
            }
        }
        return false;
    }
       /* if(sizeInBits < 256){
            tryTime=27;
        } else if(sizeInBits < 512){
            tryTime=15;
        } else if(sizeInBits < 768){
            tryTime=8;
        } else if(sizeInBits < 1024){
            tryTime=4;
        } else{
            tryTime=2;
        }*/


    /**
     * 多次调用素数测试,判定输入的n是否为质数
     */
    private static boolean isPrime(BigInteger n,int tryTime){
        for(int i=0;i<tryTime;i++){
            if(!passesMillerRabin(n)){
                return false;
            }
        }
        return true;
    }

    /**
     * 产生一个n bit的素数
     */
    public static BigInteger getPrime(int bitCount){
        //随机生成一个n bit的大整数
        BigInteger ret=new BigInteger(bitCount,ran);
        //如果n为偶数,则加一变为奇数
        if(!ret.testBit(0)){
            ret=ret.setBit(0);
        }
        int i=0;
        //基于素数定理,平均只需要不到n次搜索,就能找到一个素数
        while(!isPrime(ret,27)){
            ret=ret.add(BigInteger.valueOf(2));i++;
        }
        //System.out.println(String.format("try %d\ttimes",i));
        return ret;
    }
}
public class RSA{
	//get the inverse of b mod a
	public BigInteger inv(BigInteger a,BigInteger b){
		BigInteger a0=a,b0=b,t0=BigInteger.ZERO,t=BigInteger.ONE;
		BigInteger q=a0.divide(b0),r=a0.subtract(q.multiply(b0));
		while(r.compareTo(BigInteger.ZERO)>0){
			BigInteger temp=t0.subtract(q.multiply(t)).mod(a);
			t0=t;t=temp;a0=b0;b0=r;q=a0.divide(b0);r=a0.subtract(q.multiply(b0));
		}
		if(!b0.equals(BigInteger.ONE))return new BigInteger("-1");
		return t;
	}
	public static void main(String[] args){
		// TODO Auto-generated method stub
		int bitCount=256;
		BigInteger p=Utils.getPrime(bitCount),q=Utils.getPrime(bitCount);
		BigInteger n=p.multiply(q);

	}

}
