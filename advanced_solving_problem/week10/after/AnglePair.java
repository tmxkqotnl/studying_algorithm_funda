package run;
import java.util.ArrayList;
import java.util.Collections;

public class AnglePair implements Comparable<AnglePair>
{
	double from, to;
	public AnglePair(double from, double to) 
	{
		this.from = from; this.to = to;
	}
	
	boolean intersectWith(AnglePair a) 
	{
		double fromMax = Math.max(this.from, a.from);
		double toMin = Math.min(this.to, a.to);
		return fromMax<toMin;
	}
	
	AnglePair mergeWith(AnglePair a) 
	{
		if (this.intersectWith(a)) 
		{
			double fromMin = Math.min(this.from, a.from);
			double toMax = Math.max(this.to, a.to);
			return new AnglePair(fromMin,toMax);
		} else 
			return null;
	}
	
	/*
	 * p0와 p1이 이루는 각도 및 p0와 p2가 이루는 각도를 pair로 만들어 return
	 * p1과 p2가 2사분면과 3사분면, 혹은 3사분면과 2사분면에 있다면 2개의 각도 pair를 만들어 return 
	 */
	static ArrayList<AnglePair> createAnglePairList(double p0x, double p0y, 
			double p1x, double p1y, double p2x, double p2y) 
			{
		double angle1 = Math.atan2(p1y-p0y,p1x-p0x);
		double angle2 = Math.atan2(p2y-p0y,p2x-p0x);
		double angleMin = Math.min(angle1, angle2);
		double angleMax = Math.max(angle1, angle2);
		
		ArrayList<AnglePair> anglePairList = new ArrayList<AnglePair>();
		if (angleMax - angleMin <= Math.PI)
			anglePairList.add(new AnglePair(angleMin, angleMax));
		else 
		{
			anglePairList.add(new AnglePair(angleMax, Math.PI));
			anglePairList.add(new AnglePair(-Math.PI, angleMin));
		}

		return anglePairList;
	}
	static ArrayList<AnglePair> createAnglePairListByDeg(double from, double to) 
	{
		double angleMin = Math.min(from,to);
		double angleMax = Math.max(from,to);
		
		ArrayList<AnglePair> anglePairList = new ArrayList<AnglePair>();
		if(from<to){
			anglePairList.add(new AnglePair(from,to));
		}else{
			anglePairList.add(new AnglePair(from,Math.PI));
			anglePairList.add(new AnglePair(-Math.PI,to));
		}

		return anglePairList;
	}


	static boolean intersectList(ArrayList<AnglePair> apList1, ArrayList<AnglePair> apList2) 
	{
		for(AnglePair ap1: apList1) 
		{
			for(AnglePair ap2: apList2)
				if (ap1.intersectWith(ap2)) return true;
		}
		return false;
	}

	static ArrayList<AnglePair> mergeList(ArrayList<AnglePair> apList1, ArrayList<AnglePair> apList2) 
	{
		ArrayList<AnglePair> anglePairListTmp = new ArrayList<AnglePair>();
		anglePairListTmp.addAll(apList1);
		anglePairListTmp.addAll(apList2);		
		Collections.sort(anglePairListTmp);
		
		ArrayList<AnglePair> anglePairListFinal = new ArrayList<AnglePair>();
		AnglePair prev = anglePairListTmp.get(0);
		for(int i=1;i<anglePairListTmp.size();i++) 
		{
			AnglePair next = anglePairListTmp.get(i);
			if (prev.intersectWith(next)) 
			{
				prev = prev.mergeWith(next);
			} 
			else 
			{
				anglePairListFinal.add(prev);
				prev = next;
			}
		}
		anglePairListFinal.add(prev);
		
		return anglePairListFinal;
	}
	
	/*
	 * Collections.sort() method로 정렬 시 
	 * from의 오름차순으로 정렬하고
	 * from이 같으면 to의 오름차순으로 정렬하도록 함 
	 */
	@Override
	public int compareTo(AnglePair o) 
	{
		double fromDiff = this.from - o.from;
		if (fromDiff<0) return -1;
		else if (fromDiff>0) return 1;
		else 
		{
			double toDiff = this.to - o.to;
			if (toDiff<0) return -1;
			else if (toDiff>0) return 1;
			else return 0;
		}
	}
}
