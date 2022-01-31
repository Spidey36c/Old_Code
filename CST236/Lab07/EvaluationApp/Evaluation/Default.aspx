<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" Title="Select Course"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Untitled Page</title>
    <link href="StyleSheet.css" type="text/css" rel="stylesheet" />
</head>
<body>
    <form id="form1" runat="server">
    <div class="Main">
        <div id="WelcomeText">
            Welcome to the OIT Portland Course Evaluation Lab.<br />
            Select the Course to Evaluate.
        </div>
        <p>
            <asp:ObjectDataSource runat="server" ID="EvaluationODS" TypeName="DM.Evaluation.DataSource" SelectMethod="GetCourseRuns" />
            <asp:DropDownList runat="server" ID="CourseRuns" DataSourceID="EvaluationODS" DataTextField="DisplayData" DataValueField="Id" CssClass="Courses" AutoPostBack="true" AppendDataBoundItems="true">
                <asp:ListItem Text="Select Course" />
            </asp:DropDownList>
        </p>
        <p>
            <asp:Button runat="server" ID="enterEvals" Text="Evaluate Course" 
                CssClass="Enter" PostBackUrl="~/EnterEvaluation.aspx" 
                onclick="enterEvals_Click" />
        </p>
    </div>
    </form>
</body>
</html>
