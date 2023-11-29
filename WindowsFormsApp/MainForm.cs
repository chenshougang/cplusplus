using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp
{

    public partial class MainForm : Form
    {
        // 声明C语言函数
        [DllImport("ParameterList.dll")] // 这里假设example.dll是你编译C语言代码生成的动态链接库
        public static extern void PrintValues(int num, params int[] values);

        public MainForm()
        {
            InitializeComponent();
            csg_verify();
        }

        private void csg_verify()
        {
            PrintValues(5, 1, 2, 3);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            csg_verify();
        }
    }
}
