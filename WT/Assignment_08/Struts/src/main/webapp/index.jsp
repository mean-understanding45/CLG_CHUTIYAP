<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Struts</title>
</head>
<body>
	<h1>Struts Login Application</h1>
	
	<s:form action="verify" style="align:center">
	
		<s:textfield name="uname" label="Enter name (max 15 char)" /><br><br>
		
		<s:textfield name="mobile" label="Enter mobile number" /><br><br>
		
		<s:textfield name="email" label="Enter email id" /><br><br>
		
		<s:submit name="Login" align="center" />
	
	</s:form>
</body>
</html>