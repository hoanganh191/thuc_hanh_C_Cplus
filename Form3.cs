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
            dgvsach.Columns["Mota"].Visible= false;
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
            string soluongchu=txtsoluong.Text;
            int soluong=int.Parse(soluongchu);
            if(maloai=="")
            {
                MessageBox.Show("Bạn chưa nhập mã loại");
                return;
            } 
            if(checktrung(maloai)==false)
            {
                MessageBox.Show("Mã loại trùng"); return;
            }    
            if(soluong<=90)
            {
                MessageBox.Show("số lương ko hợp lệ");
                return;
            }    
            if(con.State == ConnectionState.Closed)  {con.Open();}
            string sql= "insert into sach values(@maloai,@tenloai,@mota,@soluong)";
            SqlCommand cmd= new SqlCommand(sql, con);
            cmd.Parameters.Add("@maloai", SqlDbType.NVarChar, 50).Value = maloai;
            cmd.Parameters.Add("@tenloai",SqlDbType.NVarChar,50).Value=tenloai;
            cmd.Parameters.Add("@mota",SqlDbType.NVarChar,50).Value = mota;//lưu giá trị vào  sql
            cmd.Parameters.Add("@soluong",SqlDbType.Int).Value=soluong;
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
            txtsoluong.Text = dgvsach.Rows[hangdangchon].Cells[3].Value.ToString();
        }

        private void btnxoa_Click(object sender, EventArgs e)
        {
            if(txtmaloai.Text=="")
            {
                MessageBox.Show("Chua chon o"); return;
            }
        string maloai = txtmaloai.Text;
            if(con.State == ConnectionState.Closed)  con.Open();
            string sql = "delete from sach where Maloai=@maloai";
            SqlCommand cmd = new SqlCommand(sql, con);
            cmd.Parameters.Add("@maloai", SqlDbType.NVarChar, 50).Value = maloai;
            cmd.ExecuteNonQuery();
            cmd.Dispose();
            con.Close();
            MessageBox.Show("xoa thanh cong");
            loaddgv();
        }

        private void btnSua_Click(object sender, EventArgs e)
        {
            if(txtmaloai.Text=="")
            {
                MessageBox.Show("Chua chon o");
                return;
            }
            string maloai= txtmaloai.Text;
            string tenloai= txttenloai.Text;
            string mota= txtmota.Text;
            string soluong=txtsoluong.Text;
            if (con.State == ConnectionState.Closed) con.Open();
            string sql = "update sach set Tenloai=@tenloai,Mota=@tenloai,Soluong=@soluong where Maloai=@maloai";
            SqlCommand cmd= new SqlCommand(sql, con);
            cmd.Parameters.Add("@maloai",SqlDbType.NVarChar,50).Value = maloai;
            cmd.Parameters.Add("@tenloai",SqlDbType.NVarChar,50).Value= tenloai;
            cmd.Parameters.Add("@mota",SqlDbType.NVarChar,50).Value= mota;
            cmd.Parameters.Add("@soluong",SqlDbType.Int).Value= soluong;
            cmd.ExecuteNonQuery();
            cmd.Dispose();
            con.Close();
            MessageBox.Show("sua thanh cong");
            loaddgv();
        }

        private void btntimkiem_Click(object sender, EventArgs e)
        {
            string maloai = txtmaloai.Text;
            string tenloai = txttenloai.Text;
            string mota= txtmota.Text;
            string soluongchu = txtsoluong.Text;
            //int soluong=int.Parse(soluongchu);
            if(con.State == ConnectionState.Closed)
                con.Open();
            string sql = "select * from sach where Maloai like @maloai and Tenloai like @tenloai and Mota like @mota ";
            SqlCommand cmd = new SqlCommand(sql,con);
            cmd.Parameters.Add("@maloai",SqlDbType.NVarChar,50).Value="%"+maloai+"%";
            cmd.Parameters.Add("@tenloai", SqlDbType.NVarChar, 50).Value = "%"+tenloai+"%";
            cmd.Parameters.Add("@mota",SqlDbType.NVarChar,50).Value="%"+mota+"%";
            //cmd.Parameters.Add("@soluong", SqlDbType.Int).Value = soluong;
            SqlDataAdapter adapter = new SqlDataAdapter(cmd);
            DataTable dt = new DataTable();
            adapter.Fill(dt);
            dgvsach.DataSource= dt;
            dgvsach.Refresh();
            cmd.Dispose();
          con.Close();
        }
    }


}
