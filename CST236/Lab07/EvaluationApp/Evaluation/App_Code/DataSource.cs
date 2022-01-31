using System;
using System.Collections.Generic;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Data.SqlClient;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

/// <summary>
/// Summary description for DataSource
/// </summary>

namespace DM.Evaluation
{
    public class DataSource
    {
        static string connectionString = ConfigurationManager.ConnectionStrings["Evaluation"].ConnectionString;
        static public List<CourseRun> GetCourseRuns()
        {
            List<CourseRun> courseRuns = new List<CourseRun>();

            using (SqlConnection conn = new SqlConnection(connectionString))
            {
                using(SqlCommand cmd = conn.CreateCommand())
                {
                    conn.Open();
                    cmd.CommandType = CommandType.StoredProcedure;
                    cmd.CommandText = "get_courseRuns";

                    SqlDataReader rdr = cmd.ExecuteReader();

                    while (rdr.Read())
                    {
                        CourseRun run = new CourseRun();
                        run.Id = rdr.GetInt32(0);
                        run.CourseDescription = rdr["CourseDescription"].ToString();
                        run.CourseName = rdr["CourseName"].ToString();
                        run.LocationDescription = rdr["LocationDescription"].ToString();
                        run.LocationName = rdr["LocationName"].ToString().ToString();
                        run.RunDate = rdr.GetDateTime(5);

                        courseRuns.Add(run);
                    }
                }
            }
            return courseRuns;
        }

        static public void AddEvaluation(int courseRunId, bool isAnonymous, string name, string email, string companyName, int courseEval, string courseEvalNotes, int instructorEval, string instructorEvalNotes, int facilitiesEval, string facilitiesEvalNotes)
        {
            using (SqlConnection conn = new SqlConnection(connectionString))
            {
                using (SqlCommand cmd = conn.CreateCommand())
                {
                    conn.Open();
                    cmd.CommandType = CommandType.StoredProcedure;
                    cmd.CommandText = "add_courseEvaluation";
                    cmd.Parameters.Add(new SqlParameter("CourseRunId", courseRunId));
                    if (isAnonymous)
                        name = "Anonymous";
                    cmd.Parameters.Add(new SqlParameter("Name", name));
                    cmd.Parameters.Add(new SqlParameter("EMail", email));
                    cmd.Parameters.Add(new SqlParameter("Company", companyName));
                    cmd.Parameters.Add(new SqlParameter("CourseMark", courseEval));
                    cmd.Parameters.Add(new SqlParameter("CourseEvalNotes", courseEvalNotes));
                    cmd.Parameters.Add(new SqlParameter("InstructorMark", instructorEval));
                    cmd.Parameters.Add(new SqlParameter("InstructorEvalNotes", instructorEvalNotes));
                    cmd.Parameters.Add(new SqlParameter("FacilitiesMark", facilitiesEval));
                    cmd.Parameters.Add(new SqlParameter("FacilitiesEvalNotes", facilitiesEvalNotes));

                    cmd.ExecuteNonQuery();
                }
            }
        }
    }

    public class CourseRun
    {
        int id;

        public int Id
        {
            get { return id; }
            set { id = value; }
        }
        
        String courseName;

        public String CourseName
        {
            get { return courseName; }
            set { courseName = value; }
        }

        String courseDescription;

        public String CourseDescription
        {
            get { return courseDescription; }
            set { courseDescription = value; }
        }
        String locationName;

        public String LocationName
        {
            get { return locationName; }
            set { locationName = value; }
        }
        String locationDescription;

        public String LocationDescription
        {
            get { return locationDescription; }
            set { locationDescription = value; }
        }
        DateTime runDate;

        public DateTime RunDate
        {
            get { return runDate; }
            set { runDate = value; }
        }

        public String DisplayData
        {
            get { return string.Format("{0},{1},{2}", CourseName, LocationName, RunDate.ToShortDateString()); }
        }
    }
}
