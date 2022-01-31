using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using DM.Evaluation;

public partial class EnterEvaluation : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (PreviousPage != null)
        {
            CourseRunId.Value = PreviousPage.CourseRunId;
            CourseTitle.Text = PreviousPage.CourseTitle;
        }

        if (IsPostBack)
        {
            if (allowAnon.Checked)
            {
                nameValidator.Enabled = false;
            }
        }
    }

    protected void AddEvaluation_Click(object sender, EventArgs e)
    {
        if (Page.IsValid)
        {
            int courseEval = 10;
            int instructorEval = 10;
            int facilitiesEval = 10;
            int courseRunId;

            int.TryParse(CourseRunId.Value, out courseRunId);
            int.TryParse(courseMark.Text, out courseEval);
            int.TryParse(instructorMark.Text, out instructorEval);
            int.TryParse(facilitiesMark.Text, out facilitiesEval);
            DataSource.AddEvaluation(courseRunId, allowAnon.Checked, name.Text, email.Text, company.Text, courseEval, courseComment.Text, instructorEval, instructorComment.Text, facilitiesEval, facilitiesComment.Text);
            Response.Redirect("~/Confirmation.aspx");
        }
    }
}
