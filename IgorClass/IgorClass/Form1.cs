using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace IgorClass
{
    public partial class Form1 : Form
    {
        class User
        {
            string name;
            string surname;

            public User(string n, string sn)
            {
                name = n;
                surname = sn;
            }
            public override string ToString()
            {
                return name + " " + surname;
            }
        }
        List<User> users;
        public Form1()
        {
            InitializeComponent();
            users = new List<User>();
        }

        private void BtnAdd_Click(object sender, EventArgs e)
        {
            string name = txtBoxName.Text;
            string surname = txtBoxSurname.Text;
            if(!char.IsUpper(name[0]) || !char.IsUpper(surname[0]))
            {
                lblOut.Text = "Name and Surname must start from upper letter";
                return;
            }
            foreach (var l in name)
            {
                if (!char.IsLetter(l))
                {
                    lblOut.Text = "Name and Surname must have only letter";
                    return;
                }
            }
            foreach (var l in surname)
            {
                if (!char.IsLetter(l))
                {
                    lblOut.Text = "Name and Surname must have only letter";
                    return;
                }
            }
            users.Add(new User(name, surname));
            lblOut.Text = "";
            foreach (var user in users)
                lblOut.Text += user + "\n";
        }
    }
}
