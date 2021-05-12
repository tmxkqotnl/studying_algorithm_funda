package run;
import java.util.ArrayList;


public class Map 
{
	int N;	// (s,t) = (1,1) ~ (N,N) 까지의 NxN개 cell을 갖는 map
	boolean obstacleMap[][];	// N+1 by N+1 배열. map의 cell[t][s]에 대해 true이면 장애물 있고 false이면 장애물 없음 
	int sPlayer, tPlayer;	// player의 s(가로)와 t(세로) 좌표	
	ArrayList<AnglePair> filterList = new ArrayList<AnglePair>();
	int shade[][];	// map의 cell[t][s]에 대한 그림자 정도 (0: 그림자 없음, 1: 그림자 있음)
	
	public static double cellLength = 1.0;	// 각 cell의 가로세로 길이. 각 cell의 4개 포인트의 xy좌표 계산에 사용

	public Map(int N, boolean obstacleMap[][], int sPlayer, int tPlayer, double from, double to) 
	{
		this.N = N; this.obstacleMap = obstacleMap;
		this.sPlayer = sPlayer; this.tPlayer = tPlayer;	// player의 초기 좌표는 장애물이 없는 곳이라 가정 
		this.filterList = AnglePair.createAnglePairListByDeg(to,from);
		shade = new int[N+1][N+1];		
	}
	
	public void setPlayerPosition(int sPlayer, int tPlayer) 
	{
		//if (this.obstacleMap[tPlayer][sPlayer] == false)	// 장애물이 없는 곳으로만 이동 가능
			this.sPlayer = sPlayer; this.tPlayer = tPlayer;
	}
	
	/*
	 * 장애물 map 출력
	 */
	public void printMap() 
	{		
		for(int t=N;t>=1;t--) 
		{
			for(int s=1;s<=N;s++) 
			{
				System.out.print(obstacleMap[t][s]?"1":"0"); 
			}
			System.out.println();
		}
		System.out.println();
	}
	
	/*
	 * shade[][]에 저장된 음영 출력
	 * createShade() 호출 후에 이 함수를 호출할 것
	 */
	public void printShade() 
	{
		for(int t=N;t>=1;t--) 
		{
			for(int s=1;s<=N;s++) 
			{
				if (t==tPlayer && s==sPlayer) System.out.print("P");
				else if (obstacleMap[t][s]) System.out.print("1");
				else System.out.print(shade[t][s]>0?"x":"o"); 
			}
			System.out.println();
		}
		System.out.println();
	}
		
	/*
	 * player의 현재 위치를 기준으로 그림자가 있는 cell 다시 계산
	 * player의 위치가 바뀌면 다시 호출할 것
	 */
	public void createShade() 
	{
		shade = new int[N+1][N+1];	// shade 리셋
		ArrayList<AnglePair> obstacleList = new ArrayList<AnglePair>();	// player 현재 위치 기준으로 장애물이 있는 각도 범위의 목록 
		// player의 현재 위치로부터 최대로 얼마나 멀리 떨어진 거리까지 정사각형을 그리며 조사해야 하는지 결정
		int distanceMax = Math.max(Math.max(Math.max(N-sPlayer, N-tPlayer),sPlayer-1),tPlayer-1);
		
		for(int distance=1;distance<=distanceMax;distance++) 
		{
			int i=0;
			while (i<distance) 
			{
				obstacleList = checkCell(obstacleList, sPlayer-i, tPlayer+distance); // up
				obstacleList = checkCell(obstacleList, sPlayer+distance, tPlayer+i); // right
				obstacleList = checkCell(obstacleList, sPlayer+i, tPlayer-distance); // down
				obstacleList = checkCell(obstacleList, sPlayer-distance, tPlayer-i); // left
				
				i += 1;
				obstacleList = checkCell(obstacleList, sPlayer+i, tPlayer+distance); // up
				obstacleList = checkCell(obstacleList, sPlayer+distance, tPlayer-i); // right
				obstacleList = checkCell(obstacleList, sPlayer-i, tPlayer-distance); // down
				obstacleList = checkCell(obstacleList, sPlayer-distance, tPlayer+i); // left
			}			
		}
	}
	
	ArrayList<AnglePair> checkCell(ArrayList<AnglePair> obstacleList, int s, int t) 
	{
		if (1<=s && s<=N && 1<=t && t<=N) 
		{	
			 // 사용자의 중심(사용자가 위치한 격자의 중심)의 xy 좌표 계산. 각도 계산 위함
			double p0x = sPlayer*cellLength - cellLength/2.0;
			double p0y = tPlayer*cellLength - cellLength/2.0;
			
			if (obstacleMap[t][s]) 
			{	
				// 장애물이 있는 경우
				double[] xyCoordinates = getXYCoordinatesOfCell(s, t);
				ArrayList<AnglePair> apList = AnglePair.createAnglePairList(p0x, p0y, 
						xyCoordinates[0], xyCoordinates[1], xyCoordinates[2], xyCoordinates[3]);
				obstacleList = AnglePair.mergeList(obstacleList, apList);	// 기존 장애물 리스트에 각도 추가
				shade[t][s] = 1;	// 음영처리
			} 
			else 
			{				
				// 장애물이 없는 경우
				double[] xyCoordinates = getXYCoordinatesOfCell(s, t);
				ArrayList<AnglePair> apList = AnglePair.createAnglePairList(p0x, p0y, 
						xyCoordinates[0], xyCoordinates[1], xyCoordinates[2], xyCoordinates[3]);
				if (AnglePair.intersectList(apList, obstacleList) || AnglePair.intersectList(apList, filterList)) // 기존 장애물 각도와 겹칠 때 음영처리 
					shade[t][s] = 1;
			}			
		}
		
		return obstacleList;
	}	
	
	/*
	 * 검사 대상인 cell에 대해 (sCell, tCell은 각각 이 cell의 가로좌표와 세로좌표)
	 * player로부터의 각도 범위를 계산하기 위한 2개 점의 s, t좌표를 계산하여
	 * 이들을 double[] 배열에 차례로 넣어 반환 
	 */
	double[] getXYCoordinatesOfCell(int sCell, int tCell) 
	{
		double[] xyCoordinates = new double[4];
	
		if (tPlayer<tCell) 
		{
			if (sPlayer>sCell) 
			{
				xyCoordinates[0]=(sCell-1)*cellLength; xyCoordinates[1]=(tCell-1)*cellLength;
				xyCoordinates[2]=sCell*cellLength; xyCoordinates[3]=tCell*cellLength;
			} 
			else if (sPlayer==sCell) 
			{
				xyCoordinates[0]=(sCell-1)*cellLength; xyCoordinates[1]=(tCell-1)*cellLength;
				xyCoordinates[2]=sCell*cellLength; xyCoordinates[3]=(tCell-1)*cellLength;				
			} 
			else if (sPlayer<sCell) 
			{
				xyCoordinates[0]=(sCell-1)*cellLength; xyCoordinates[1]=tCell*cellLength;
				xyCoordinates[2]=sCell*cellLength; xyCoordinates[3]=(tCell-1)*cellLength;
			}
		} 
		else if (tPlayer==tCell) 
		{
			if (sPlayer>sCell) 
			{				
				xyCoordinates[0]=sCell*cellLength; xyCoordinates[1]=tCell*cellLength;
				xyCoordinates[2]=sCell*cellLength; xyCoordinates[3]=(tCell-1)*cellLength;
			} 
			else if (sPlayer==sCell) 
			{
				// this case does NOT happen
			} 
			else if (sPlayer<sCell) 
			{
				xyCoordinates[0]=(sCell-1)*cellLength; xyCoordinates[1]=tCell*cellLength;
				xyCoordinates[2]=(sCell-1)*cellLength; xyCoordinates[3]=(tCell-1)*cellLength;
			}
		} 
		else if (tPlayer>tCell) 
		{
			if (sPlayer>sCell) 
			{
				xyCoordinates[0]=(sCell-1)*cellLength; xyCoordinates[1]=tCell*cellLength;
				xyCoordinates[2]=sCell*cellLength; xyCoordinates[3]=(tCell-1)*cellLength;
			} 
			else if (sPlayer==sCell) 
			{
				xyCoordinates[0]=(sCell-1)*cellLength; xyCoordinates[1]=tCell*cellLength;
				xyCoordinates[2]=sCell*cellLength; xyCoordinates[3]=tCell*cellLength;
			} 
			else if (sPlayer<sCell) 
			{
				xyCoordinates[0]=(sCell-1)*cellLength; xyCoordinates[1]=(tCell-1)*cellLength;
				xyCoordinates[2]=sCell*cellLength; xyCoordinates[3]=tCell*cellLength;
			}
		}
		
		return xyCoordinates;
	}	
	
}
