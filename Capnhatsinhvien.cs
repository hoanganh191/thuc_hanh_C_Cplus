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

        private void Load_lophoc() //Ham khong can tham chieu ( ham tu viet k can chi vao giao dien )
        {
            //B1 : ket noi DB
            if (con.State == ConnectionState.Closed) con.Open();

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

        private void Load_sinhvien(string maSV, string gioiTinh, string hoTen, string Malop) //Ham tu viet
        {
            if (con.State == ConnectionState.Closed) con.Open();

            

            //Tao doi tuong commad de thuc thi cau lenh
            string sql = "select Sinhvien.*,Tenlop from Sinhvien,Lophoc " +
            "where Sinhvien.Malop=Lophoc.Malop and " +
            "Masv like '%'+@masv+'%' and Hoten like '%'+@hoten+'%' and " +
            "Gioitinh like '%'+@gioitinh+'%' and " +
            "Sinhvien.Malop like '%'+@malop+'%'";

            SqlCommand cmd = new SqlCommand(sql, con);
            cmd.Parameters.Add("@masv", SqlDbType.NVarChar, 50).Value = maSV;
            cmd.Parameters.Add("@hoten", SqlDbType.NVarChar, 100).Value = hoTen;
            cmd.Parameters.Add("@malop", SqlDbType.NVarChar,50).Value = Malop;
            cmd.Parameters.Add("@gioitinh", SqlDbType.NVarChar, 50).Value = gioiTinh;

            SqlDataAdapter da = new SqlDataAdapter();
            da.SelectCommand = cmd;
            DataTable tb = new DataTable();
            da.Fill(tb);
            cmd.Dispose();
            con.Close();

            dgvSinhvien.DataSource = tb;
            dgvSinhvien.Refresh();


        }
        //Ham nay can tham chieu giao dien, an dup vao giao dien (Form) de co ham nay 
        private void Capnhatsinhvien_Load(object sender, EventArgs e)
        {
            Load_lophoc();
            Load_sinhvien("", "", "", "");

        }
        
        private void btnLuu_Click(object sender, EventArgs e) //Ham nay an dup vao nut luu o giao dien
        {
            string msv = txtMasinhvien.Text.Trim();
            string ht = txtHoten_cn.Text.Trim();
            string gt = cbGioitinh_cn.SelectedItem.ToString();
            DateTime ngs = dtNgaySinh.Value;
            string ml = cboLop.SelectedValue.ToString(); //Lay du lieu tu Datba base thi dung Value
            string dt = txtDienthoai_cn.Text.Trim();
            string dc = txtDiachi.Text.Trim();

            //B2 ket noi DB
            if (con.State == ConnectionState.Closed) con.Open();

            //B3 them commad de thuc thi cau lenh sql
            string sql = "Insert Sinhvien Values(@masv,@hoten,@ngaysinh,@gioitinh,@malop,@sdt,@diachi)";
            SqlCommand cmd = new SqlCommand(sql, con);
            cmd.Parameters.Add("@masv", SqlDbType.NVarChar, 50).Value = msv;
            cmd.Parameters.Add("@hoten",SqlDbType.NVarChar,100).Value = ht;
            cmd.Parameters.Add("@ngaysinh",SqlDbType.Date).Value = ngs;
            cmd.Parameters.Add("@gioitinh", SqlDbType.NVarChar, 50).Value = gt;
            cmd.Parameters.Add("@malop", SqlDbType.NVarChar, 50).Value = ml;
            cmd.Parameters.Add("@sdt", SqlDbType.NVarChar, 50).Value = dt;
            cmd.Parameters.Add("@diachi", SqlDbType.NVarChar, 200).Value = dc;
            cmd.ExecuteNonQuery();
            cmd.Dispose();
            con.Close();

            MessageBox.Show("Them moi thanh cong");
            Load_sinhvien("", "", "", "");
            

        }
        // ham nay chinh su kien event Cell Click cua DataGripview
        private void dgvSinhvien_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            int i = e.RowIndex;
            txtMasinhvien.Text = dgvSinhvien.Rows[i].Cells[0].Value.ToString();
            txtHoten_cn.Text = dgvSinhvien.Rows[i].Cells[1].Value.ToString();
            dtNgaySinh.Value = DateTime.Parse(dgvSinhvien.Rows[i].Cells[2].Value.ToString());
            cbGioitinh_cn.SelectedItem = dgvSinhvien.Rows[i].Cells[3].Value.ToString();
            cboLop.SelectedValue = dgvSinhvien.Rows[i].Cells[4].Value.ToString() ;
            txtDienthoai_cn.Text = dgvSinhvien.Rows[i].Cells["Dienthoai"].Value.ToString();
            txtDiachi.Text = dgvSinhvien.Rows[i].Cells["Diachi"].Value.ToString();
            txtMasinhvien.Enabled = false;
        }

        private void btnTimkiem_Click(object sender, EventArgs e) //Ham nay la an dup 2 lan vao nut tim kiem
        {
            //Lay du lieu tu cac control dua vao bien
            string msv = txtMasinhvien_tk.Text.Trim();
            string ht = txtHoten_tk.Text.Trim();
            string gt;
            //Truong hop de gioi tinh trong
            if (cbGioitinh_tk.SelectedItem == null) gt = "";
            else gt = cbGioitinh_tk.SelectedItem.ToString();

            string ml = cboLop_tk.SelectedValue.ToString();
            //Tim kiem
            Load_sinhvien(msv,ht,gt,ml);

        }

        private void btnSua_Click(object sender, EventArgs e)
        {

        }
    }
}
