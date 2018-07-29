import java.util.Scanner;
import java.util.*;
import java.lang.*;
class PAGING
{
	public static void main(String args[])
	{
		int PageNo,PageSize,FrameNo;
		Scanner input=new Scanner(System.in);
		System.out.print("Enter The Number Of Pages : ");
		PageNo=input.nextInt();
		System.out.println("");
		System.out.print("Enter The Size Of Page(Byte) : ");
		PageSize=input.nextInt();
		System.out.println("");
		System.out.print("Enter The Number Of Frames : ");
		FrameNo=input.nextInt();
		System.out.println("");
		System.out.println("Enter The Mapped Frames Corresponding To Following Pages( consider 0) : ");
		LinkedList Frame=new LinkedList();
		for(int i=0;i<PageNo;i++)
		{
			System.out.print("page "+i+":");
			int temp=input.nextInt();
			Frame.add(temp);
			System.out.println("");
		}
		System.out.println("Following Is The Given Mapping :");
		System.out.print("PAGE NO      ");
		System.out.print("FRAME NO");
		System.out.println("");
		Object[] array = Frame.toArray();
		for(int i=0;i<PageNo;i++)
		{
			System.out.print(i);
			System.out.print("      ---->    ");
			System.out.println(array[i]);
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
