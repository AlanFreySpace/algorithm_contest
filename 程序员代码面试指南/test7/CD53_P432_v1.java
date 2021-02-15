package test7;

import java.util.Scanner;

public class CD53_P432_v1{
	//�õ�����ֵ����
    public int changeDisGetInit(int[] oil,int[] dis){
        int init=-1;
        for(int i=0;i<oil.length;i++){
            dis[i]=oil[i]-dis[i];
            if(dis[i]>=0)
                init=i;
        }
        return init;
    }
    //��һ��λ��
    public int lastIndex(int index,int size){
        return index==0?size-1:index-1;
    }
    //��һ��λ��
    public int nextIndex(int index,int size){
        return index==size-1?0:index+1;
    }
    /*
     * need����Ҫdis[start]���������ֵ����ֵ��
     * ���ڵ���0
     */
    public void connectGood(int[] dis,int start,int init,int[] res){
        long need=0;
        while(start!=init){
            if(dis[start]<need)
                need-=dis[start];
            else{
                need=0;
                res[start]=1;
            }
            start=lastIndex(start,dis.length);
        }
    }
    
    public int[] getGoodPoint(int[] oil,int[] dis){
        int init=changeDisGetInit(oil,dis);
        int[] res=new int[dis.length];
        if(init==-1)
            return res;
        int start=init,end=nextIndex(init,dis.length);
        long need=0,rest=0;
        do{
        	/*
        	 * ��if����������1�������ע��end���ֵ��ǰ
        	 * ��δ�����ǣ������������ʱ����֮ǰ������
        	 * һ��[start,end)���򣬸������ۼ���[start,end)��
        	 * ����ֵ����������ۼӺ�С��0(��ǰrestС��0)����˲���
        	 * �����µ�start,���Խ�rest���㵽���ڵ���0�����start
        	 * �����Գ��Ե�endλ��
        	 */
            if(start!=init&&lastIndex(end,dis.length)==start)
                break;
            /*
             * ��ǰ����ȼ��Ϊneed����Ҫdis[start]�����䣬��
             * ��ǰstart�㴿��ֵ��С��ֻ�ܲ��ֲ���(��ʹ��need����
             * ����)
             */
            if(need>dis[start])
                need-=dis[start];
            /*
             * ��ǰstart�����ȫ���������ȼ�ϣ��ҿ�ʣ��ȼ�ϣ�
             * ����������ʹ��(need�Ƿ���Ҳ������start����ĵ�
             * �����ȼ�ϣ������ȼ���Ȼ��rest��Ҳ������������
             * �ģ���startԶ�ĵ����ȼ���)
             */
            else{
                rest+=(dis[start]-need);
                need=0;
                /*
                 * ���������䣬��������������������
                 * 1.���䵽ĳ��ʱ��rest<0����ʱend=������һ����(
                 * ��ʱend���ֵ��δ�����ǣ��ɼ����Ͽ�����Ķ���)����ʱ��Ҫ����
                 * �������䣬����rest
                 * 2.���䵽start==end,��ʱ���е�ֵ�����ۼ��ˣ�˵��
                 * �ҵ�һ�����ó����㣬��ʱֻ�����connectGood���̣�����[start+1,
                 * init)��Щ�㼴�ɡ�
                 */
                while(rest>=0&&start!=end){
                    rest+=dis[end];
                    end=nextIndex(end,dis.length);
                }
                if(rest>=0){
                    res[start]=1;
                    connectGood(dis,lastIndex(start,dis.length),init,res);
                    break;
                }
            }
            start=lastIndex(start,dis.length);
        }while(start!=init);
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] oil=new int[N];
        int[] dis=new int[N];
        for(int i=0;i<N;i++)
            oil[i]=sc.nextInt();
        for(int i=0;i<N;i++)
            dis[i]=sc.nextInt();
        CD53_P432_v1 ma=new CD53_P432_v1();
        int[] res=ma.getGoodPoint(oil,dis);
        for(int i=0;i<N;i++)
            System.out.print(res[i]+" ");
        sc.close();
    }
}