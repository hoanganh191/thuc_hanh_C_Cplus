using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tuan6
{
    public partial class Capnhatsinhvien : Form
    {
        SqlConnection con = new SqlConnection("Data Source=ADMIN;Initial Catalog=74DCTT23_Quanlythuvien;Integrated Security=True;Encrypt=False");
        public Capnhatsinhvien()
        {
            InitializeComponent();
        }

        private void Load_lophoc()
        {
            //B1 : ket noi DB
            if (con.State == ConnectionState.Open) con.Open();

            //B2: tao doi tuong commad de thuc hien cau lenh sql
            string sql = "Select * From Lophoc";
            SqlCommand cmd = new SqlCommand(sql,con);

            //B3 tao doi tuong dataAdapter de lay ket qua tu cmd
            SqlDataAdapter da = new SqlDataAdapter();
            da.SelectCommand = cmd;

            //B4 tao doi tuong data table de lay du lieu tu da
            DataTable tb = new DataTable();
            da.Fill(tb);
            cmd.Dispose();
            con.Close();

            //Them 1 dong moi vao vi tri dau tien ban tb
            DataRow r = tb.NewRow();
            r["Malop"] = "";
            r["Tenlop"] = "-----Chon lop hoc------";
            tb.Rows.InsertAt(r, 0);

            //B5: do du lieu tu tb vao combo box
            cboLop_tk.DataSource = tb;
            cboLop_tk.DisplayMember = "Tenlop";
            cboLop_tk.ValueMember = "Malop";

            //Do dl tu tb vao combo box cbLop
            cboLop.DataSource = tb;
            cboLop.DisplayMember = "Tenlop";
            cboLop.ValueMember = "Malop";

        }

        private void Capnhatsinhvien_Load(object sender, EventArgs e)
        {
            Load_lophoc();

        }
    }
}
