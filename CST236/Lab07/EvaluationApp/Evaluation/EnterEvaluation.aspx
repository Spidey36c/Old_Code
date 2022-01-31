<%@ Page Language="C#" AutoEventWireup="true" CodeFile="EnterEvaluation.aspx.cs"
    Inherits="EnterEvaluation" Title="Enter Evaluation"%>

<%@ PreviousPageType VirtualPath="~/Default.aspx" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
    <link href="StyleSheet.css" type="text/css" rel="stylesheet" />

    <script type="text/javascript">

    if(window.addEventListener)
        window.addEventListener("load", pageLoad, false);
    if(window.attachEvent)
        window.attachEvent("onload", pageLoad);


    function pageLoad()
    {
        var allowAnon;

        if(window.addEventListener)
        {
            allowAnon = document.getElementById('allowAnon');
            allowAnon.addEventListener('click', DisableName, false);
        }

        if(window.attachEvent)
        {
            allowAnon = document.getElementById('allowAnon');
            allowAnon.attachEvent('onclick', DisableName);
        }

        if(allowAnon.checked)
        {
            var nameBox = document.getElementById('name');
            nameBox.disabled = true;
        }
    }

    function DisableName()
    {
        var nameBox = document.getElementById('name');
        var nameValidator = document.getElementById('nameValidator');
        if(nameBox)
        {
            nameBox.disabled = !nameBox.disabled;
        }
        if(nameBox.disabled)
        {
            ValidatorEnable(nameValidator, false);
        }
        else
        {
            ValidatorEnable(nameValidator, true);
        }
    }
    </script>

</head>
<body>
    <form id="form1" runat="server">
        <div class="Main">
            <asp:HiddenField runat="server" ID="CourseRunId" />
            <table id="EnterEvaluations">
                <tr>
                    <td colspan="4" rowspan="2" class="Title">
                        Enter Evaluation for <asp:Label runat="server" id="CourseTitle" />
                     </td>
                </tr>
                <tr>
                </tr>
                <tr>
                    <td rowspan="3" class="Separator HorizSeparator">
                        Personal
                    </td>
                    <td class="Labels">
                        <asp:Label runat="server" ID="_name" Text="Name: " />
                    </td>
                    <td>
                        <asp:TextBox runat="server" ID="name" />
                    </td>
                    <td>
                        <asp:CheckBox Text="Anonymous" runat="server" ID="allowAnon" />
                    </td>
                    <td class="Validation">
                        <asp:RequiredFieldValidator runat="server" ID="nameValidator" ControlToValidate="name"
                            Display="Dynamic" Text="Field Required" ForeColor="" />
                    </td>
                </tr>
                <tr>
                    <td class="Labels">
                        <asp:Label runat="server" ID="Label1" Text="Email: " /></td>
                    <td colspan="2">
                        <asp:TextBox runat="server" ID="email" />
                    </td>
                    <td>
                    </td>
                </tr>
                <tr>
                    <td class="Labels HorizSeparator">
                        <asp:Label runat="server" ID="Label2" Text="Company Name: " /></td>
                    <td colspan="2" class="HorizSeparator">
                        <asp:TextBox runat="server" ID="company" />
                    </td>
                    <td class="Validation">
                    </td>
                </tr>
                <tr>
                    <td rowspan="2" class="Separator HorizSeparator">
                        Course
                    </td>
                    <td class="Labels">
                        <asp:Label runat="server" ID="Label3" Text="Grade: " ToolTip="Course Marks Out of 10" /></td>
                    <td colspan="2">
                        <asp:TextBox runat="server" ID="courseMark" Width="15" />
                    </td>
                    <td class="Validation">
                        <asp:RequiredFieldValidator runat="server" ID="courseMarksVal" ControlToValidate="courseMark"
                            Display="Dynamic" Text="Field Required" ForeColor="" />
                        <asp:RangeValidator runat="server" ID="RequiredFieldValidator1" ControlToValidate="courseMark"
                            Display="Dynamic" Text="Value Must be Beween 1 and 10" MinimumValue="1" MaximumValue="10"
                            Type="Integer" ForeColor="" />
                    </td>
                </tr>
                <tr>
                    <td class="Labels HorizSeparator">
                        <asp:Label runat="server" ID="Label4" Text="Comment: " ToolTip="Enter any comments you have about the course" /></td>
                    <td colspan="2" class="HorizSeparator">
                        <asp:TextBox runat="server" ID="courseComment" TextMode="MultiLine" CssClass="Comments" />
                    </td>
                    <td class="Validation">
                    </td>
                </tr>
                <tr>
                    <td rowspan="2" class="Separator HorizSeparator">
                        Instructor
                    </td>
                    <td class="Labels HorizSeparator">
                        <asp:Label runat="server" ID="Label5" Text="Grade: " ToolTip="Instructor Marks Out of 10" /></td>
                    <td colspan="2" class="HorizSeparator">
                        <asp:TextBox runat="server" ID="instructorMark" Width="15" />
                    </td>
                    <td class="Validation">
                        <asp:RequiredFieldValidator runat="server" ID="RequiredFieldValidator2" ControlToValidate="instructorMark"
                            Display="Dynamic" Text="Field Required" ForeColor="" />
                        <asp:RangeValidator runat="server" ID="RangeValidator1" ControlToValidate="instructorMark"
                            Display="Dynamic" Text="Value Must be Beween 1 and 10" MinimumValue="1" MaximumValue="10"
                            Type="Integer" ForeColor="" />
                    </td>
                </tr>
                <tr>
                    <td class="Labels HorizSeparator">
                        <asp:Label runat="server" ID="Label6" Text="Comment: " ToolTip="Enter any comments you have about the instructor" /></td>
                    <td colspan="2" class="HorizSeparator">
                        <asp:TextBox runat="server" ID="instructorComment" TextMode="MultiLine" CssClass="Comments" />
                    </td>
                    <td class="Validation">
                    </td>
                </tr>
                <tr>
                    <td rowspan="2" class="Separator HorizSeparator">
                        Facilities
                    </td>
                    <td class="Labels">
                        <asp:Label runat="server" ID="Label7" Text="Grade: " ToolTip="Facilities Marks Out of 10" /></td>
                    <td colspan="2">
                        <asp:TextBox runat="server" ID="facilitiesMark" Width="15" />
                    </td>
                    <td class="Validation">
                        <asp:RequiredFieldValidator runat="server" ID="RequiredFieldValidator3" ControlToValidate="facilitiesMark"
                            Display="Dynamic" Text="Field Required" ForeColor="" />
                        <asp:RangeValidator runat="server" ID="RangeValidator2" ControlToValidate="facilitiesMark"
                            Display="Dynamic" Text="Value Must be Beween 1 and 10" MinimumValue="1" MaximumValue="10"
                            Type="Integer" ForeColor="" />
                    </td>
                </tr>
                <tr>
                    <td class="Labels HorizSeparator">
                        <asp:Label runat="server" ID="Label8" Text="Comment: " ToolTip="Enter any comments you have about the facilities" /></td>
                    <td colspan="2" class="HorizSeparator">
                        <asp:TextBox runat="server" ID="facilitiesComment" TextMode="MultiLine" CssClass="Comments" />
                    </td>
                    <td>
                    </td>
                </tr>
                <tr>
                    <td colspan="4" class="Title">
                        <asp:Button runat="server" ID="AddEvaluation" Text="Enter Evaluation" OnClick="AddEvaluation_Click"
                            CssClass="Enter" />
                    </td>
                </tr>
            </table>
        </div>
    </form>
</body>
</html>
