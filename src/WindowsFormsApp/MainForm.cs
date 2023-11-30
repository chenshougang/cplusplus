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
        // 声明C语言函数 // 这里假设ParameterList.dll是你编译C语言代码生成的动态链接库
        [DllImport("ParameterList.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void PrintValues(int num, params int[] values);

        public MainForm()
        {
            InitializeComponent();
            csg_verify();
        }

        private void csg_verify()
        {
            int nCount = 5;
            int[] csg_params = { 1, 2, 3, 4, 5 };
            PrintValues(nCount, csg_params);

            for(int i = 0; i < nCount; i++)
            {
                Console.WriteLine(csg_params[i]);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 打印输出的值，是随机值
            csg_verify();
            csg_verify();

            MessageBox.Show(sender.ToString());
            var xxx = sender.GetType();
            var xxxxxx = sender.GetType();
        }
    }
}
