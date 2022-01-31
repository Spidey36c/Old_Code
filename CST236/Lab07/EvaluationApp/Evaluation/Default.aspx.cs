using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

public partial class _Default : System.Web.UI.Page 
{
    public string CourseRunId
    {
        get { return CourseRuns.SelectedValue; }
    }

    public string CourseTitle
    {
        get { return CourseRuns.SelectedItem.Text; }
    }
    protected void enterEvals_Click(object sender, EventArgs e)
    {

    }
}
