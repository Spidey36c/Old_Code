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
    public void Select_OnClick(object sender, EventArgs e)
    {
        //orderedBooks.Items.Add(new ListItem(allBooks.Items[allBooks.SelectedIndex].Text, allBooks.Items[allBooks.SelectedIndex].Value));
        if (allBooks.SelectedIndex >= 0 && allBooks.SelectedIndex < allBooks.Items.Count)
        {
            if (orderedBooks.Items.FindByValue(allBooks.Items[allBooks.SelectedIndex].Value) == null)
            {
                orderedBooks.Items.Add(new ListItem(allBooks.Items[allBooks.SelectedIndex].Text, allBooks.Items[allBooks.SelectedIndex].Value));
            }
        }
    }
    protected void allBooks_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
}
