<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ page import="java.sql.*" %>
<%@ page import="javax.sql.*" %>

<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Document</title>
</head>
<body>
	
	<%

	try{
	
		Class.forName("com.mysql.cj.jdbc.Driver");
		Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/wtl","root","Tejas@2212");
		Statement st = conn.createStatement();
		
		int id = Integer.parseInt(request.getParameter("id"));
		String name = request.getParameter("name");
		String stud_class = request.getParameter("class");
		String div = request.getParameter("div");
		String city = request.getParameter("city");
		String temp_id = Integer.toString(id);
		
		int i = st.executeUpdate("insert into students_info1 values(" + temp_id + ",\"" + name + "\",\"" + stud_class + 
				"\",\"" + div + "\",\"" + city + "\");");
		
		out.println("Data is successfully inserted!");%>
		<br>
		<p>Data is inserted successfully in database.</p>
		<h1>Table Contents</h1>
		<%
		Statement statement = conn.createStatement() ;
        ResultSet resultset =statement.executeQuery("select * from students_info1;") ;
        %>
        
        <TABLE BORDER="1">
	        <TR>
	            <TH>ID</TH>
	            <TH>Name</TH>
	            <TH>Class</TH>
	            <TH>Division</TH>
	            <TH>City</TH>
	       </TR>
	        <% while(resultset.next()){ %>
	        <TR>
	            <TD> <%= resultset.getString(1) %></td>
	            <TD> <%= resultset.getString(2) %></TD>
	            <TD> <%= resultset.getString(3) %></TD>
	            <TD> <%= resultset.getString(4) %></TD>
	            <TD> <%= resultset.getString(5) %></TD>
	       </TR>
        <% } %>
       </TABLE>

	<%
	}catch(Exception e){
		System.out.print(e);
		e.printStackTrace();%>
		<p>Something went wrong.</p><br>
		<p><%= e.getMessage() %></p>
		
	<%
	}
	%>
	
</body>
</html>