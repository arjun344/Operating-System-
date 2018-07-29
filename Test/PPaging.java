import java.util.Scanner;
import java.util.*;
import java.lang.*;
class PAGING
{
	static class PageTable
	{
		 int page;
		 int frame;

		public PageTable(int pagex,int framex)
		{
			page=pagex;
			frame=framex;
		}
	}
	public static void main(String args[])
	{
		int PageNo,PageSize,FrameNo,temp1;
		Scanner input=new Scanner(System.in);
		System.out.print("Enter The Number Of Pages : ");
		PageNo=input.nextInt();
		System.out.println("");
		PageTable[] pt=new PageTable[PageNo];
		System.out.print("Enter The Size Of Page(Byte) : ");
		PageSize=input.nextInt();
		System.out.println("");
		System.out.print("Enter The Number Of Frames : ");
		FrameNo=input.nextInt();
		System.out.println("");
		System.out.println("Enter The Mapped Frames Corresponding To Following Pages( consider 0) : ");
		for(int i=0;i<PageNo;i++)
		{
			System.out.print("Page "+i+":");
			temp1=input.nextInt();
			pt[i]=new PageTable(i,temp1);
			System.out.println("");
		}
		

		System.out.println("Following Is The Given Mapping :");
		System.out.print("PAGE NO      ");
		System.out.print("FRAME NO");
		System.out.println("");
		for(int i=0;i<PageNo;i++)
		{
			System.out.print(pt[i].page);
			System.out.print("      ---->    ");
			System.out.println(pt[i].frame);
		}
		
		System.out.print("Logical Address Is (PageNo,OffSet) : ");
		double OffSet=Math.log(PageSize)/Math.log(2);
		int offSet= (int) Math.round(OffSet);
		System.out.print("("+PageNo+","+ offSet+")");
		System.out.println("");
		System.out.print("Physical Address of The Process Is (FrameNo,OffSet) : ");
		System.out.print("("+FrameNo+","+ offSet+")");
		System.out.println("");
	}	
}
