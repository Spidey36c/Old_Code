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
            Welcome to the VSTS Course Unit Testing Lab.<br />
        </div>
        <p>
            <asp:ObjectDataSource runat="server" ID="ods" SelectMethod="GetBooks" TypeName="DM.UnitTest.DataSource" />
            <asp:ListBox runat="server" ID="allBooks" DataSourceID="ods" 
                DataTextField="Title" DataValueField="Id" CssClass="BookList" 
                onselectedindexchanged="allBooks_SelectedIndexChanged" />
        </p>
        <p>
            <asp:Button runat="server" ID="SelectBook" Text="Select Book" CssClass="Enter" OnClick="Select_OnClick"/>
        </p>
        <hr />
        <p>
            <asp:ListBox ID="orderedBooks" runat="server" CssClass="BookList"/>
        </p>
    </div>
    </form>
</body>
</html>
