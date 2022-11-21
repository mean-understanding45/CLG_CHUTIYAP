

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;

import java.io.*;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.*;




@WebServlet("/ServletAssign")
public class ServletAssign extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private Connection conn;
   
    public ServletAssign() {
        super();
        // TODO Auto-generated constructor stub
    }

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		PrintWriter out;
		String title, author;
		
		title = request.getParameter("ti");
		author = request.getParameter("au");
		out = response.getWriter();
		
		try {
			
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/wtl","root","Tejas@2212");
			PreparedStatement ps = conn.prepareStatement ("select book_title, book_author from ebookshop where book_title =\""+ title + "\" and book_author = \"" + author + "\";");
			/*String new_title = "\""+title+"\"";
			String new_author = "\""+author+"\"";
			ps.setString(1, new_title);
			ps.setString(2, new_author);*/
			ResultSet rs = ps.executeQuery();

			response.setContentType("text/html;charset=utf-8");
			 if (rs.next())
			{
			
			   out.println("<HTML> <BODY>");
			    out.println("<H3>Title - " + title + " and Author - "+author+" present in table.</H3>");
			    out.println("<DIV>");
			    out.println("<TABLE border='1' style='border-collapse:collapse'>");
			    out.println("<TR>");
			    out.println("<TH bgcolor=\"#dddddd\">Book Name</TH>");
			    out.println("<TH bgcolor=\"#dddddd\">Author Name</TH>");
			    out.println("</TR>");
			    out.println("<TR>");
			    out.println("<TD>"+ title +"</TD>");
			    out.println("<TD>"+ author +"</TD>");
			    out.println("</TR>");
			    out.println("</TABLE>");
			    out.println("</DIV>");
			    out.println("</BODY></HTML>");
			    System.out.print("Query OK!");
			}
			else
			{
			   out.println("<HTML> <BODY>");
			    out.println("<H1>Invalid credentials</H1>");
			    out.println("</BODY></HTML>");
			}
			 
			conn.close();
			
		}catch(Exception e) {
			out.println(e.getMessage()); 
			response.getWriter().append("Catch error: ").append(e.getLocalizedMessage());
		}
		
		
		response.getWriter().append("Served at: ").append(request.getContextPath());
		out.flush();
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
