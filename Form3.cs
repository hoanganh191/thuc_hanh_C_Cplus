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
    public partial class Form3 : Form
    {
        SqlConnection con=new SqlConnection("Data Source=ADMIN;Initial Catalog=luyentap;Integrated Security=True;Encrypt=False");
        public Form3()
        {
            InitializeComponent();
        }
        void loaddgv()//Hàm để load dữ liệu trong dgv
        {
            if(con.State==ConnectionState.Closed) con.Open();
            string sql = "select * from sach ";
            SqlCommand cmd = new SqlCommand(sql, con);
            SqlDataAdapter adapter = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            adapter.Fill(dt);
            cmd.Dispose();
            con.Close();    
            dgvsach.DataSource = dt;
            dgvsach.Refresh();
        }

        private void Q(object sender, DataGridViewCellEventArgs e)
        {
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            loaddgv();
        }

        private void btthem_Click(object sender, EventArgs e)
        {
            string maloai=txtmaloai.Text;
            string tenloai=txttenloai.Text;
            string mota=txtmota.Text;//để nhập giá trị
            if(maloai=="")
            {
                MessageBox.Show("Bạn chưa nhập mã loại");
                return;
            } 
            if(checktrung(maloai)==false)
            {
                MessageBox.Show("Mã loại trùng"); return;
            }    
            if(con.State == ConnectionState.Closed)  {con.Open();}
            string sql= "insert into sach values(@maloai,@tenloai,@mota)";
            SqlCommand cmd= new SqlCommand(sql, con);
            cmd.Parameters.Add("@maloai", SqlDbType.NVarChar, 50).Value = maloai;
            cmd.Parameters.Add("@tenloai",SqlDbType.NVarChar,50).Value=tenloai;
            cmd.Parameters.Add("@mota",SqlDbType.NVarChar,50).Value = mota;//lưu giá trị vào  sql
            cmd.ExecuteNonQuery();
            cmd.Dispose ();
            con.Close ();
            MessageBox.Show("Thêm thành công");
            loaddgv ();//cập nhật 
        }
        bool checktrung(string ktmaloai)
        {
            if(con.State == ConnectionState.Closed) con.Open();
            string sql = "select COUNT(*) from sach where Maloai=@maloai ";
            SqlCommand cmd= new SqlCommand(sql, con);
            cmd.Parameters.Add("@maloai",SqlDbType.NVarChar,50).Value=ktmaloai;
            int kq = int.Parse(cmd.ExecuteScalar().ToString());
            if (kq > 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        private void dgvsach_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            int hangdangchon=e.RowIndex; 
            txtmaloai.Text= dgvsach.Rows[hangdangchon].Cells[0].Value.ToString();
            txttenloai.Text = dgvsach.Rows[hangdangchon].Cells[1].Value.ToString();
            txtmota.Text = dgvsach.Rows[hangdangchon].Cells[2].Value.ToString();
        }
    }
}
