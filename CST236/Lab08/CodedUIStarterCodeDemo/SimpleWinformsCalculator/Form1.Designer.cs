namespace SimpleWinformsCalculator
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lblInput1 = new System.Windows.Forms.Label();
            this.lblInput2 = new System.Windows.Forms.Label();
            this.textInput1 = new System.Windows.Forms.TextBox();
            this.textInput2 = new System.Windows.Forms.TextBox();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnSubtract = new System.Windows.Forms.Button();
            this.btnMultiply = new System.Windows.Forms.Button();
            this.btnDivide = new System.Windows.Forms.Button();
            this.textAnswer = new System.Windows.Forms.TextBox();
            this.lblAnswer = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblInput1
            // 
            this.lblInput1.AutoSize = true;
            this.lblInput1.Font = new System.Drawing.Font("Consolas", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblInput1.Location = new System.Drawing.Point(17, 22);
            this.lblInput1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblInput1.Name = "lblInput1";
            this.lblInput1.Size = new System.Drawing.Size(180, 26);
            this.lblInput1.TabIndex = 0;
            this.lblInput1.Text = "Input Number 1";
            // 
            // lblInput2
            // 
            this.lblInput2.AutoSize = true;
            this.lblInput2.Font = new System.Drawing.Font("Consolas", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblInput2.Location = new System.Drawing.Point(17, 72);
            this.lblInput2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblInput2.Name = "lblInput2";
            this.lblInput2.Size = new System.Drawing.Size(180, 26);
            this.lblInput2.TabIndex = 1;
            this.lblInput2.Text = "Input Number 2";
            // 
            // textInput1
            // 
            this.textInput1.Font = new System.Drawing.Font("Consolas", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textInput1.Location = new System.Drawing.Point(268, 22);
            this.textInput1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.textInput1.Name = "textInput1";
            this.textInput1.Size = new System.Drawing.Size(237, 32);
            this.textInput1.TabIndex = 2;
            // 
            // textInput2
            // 
            this.textInput2.Font = new System.Drawing.Font("Consolas", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textInput2.Location = new System.Drawing.Point(268, 67);
            this.textInput2.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.textInput2.Name = "textInput2";
            this.textInput2.Size = new System.Drawing.Size(237, 32);
            this.textInput2.TabIndex = 3;
            // 
            // btnAdd
            // 
            this.btnAdd.Font = new System.Drawing.Font("Consolas", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAdd.Location = new System.Drawing.Point(22, 145);
            this.btnAdd.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(116, 39);
            this.btnAdd.TabIndex = 4;
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // btnSubtract
            // 
            this.btnSubtract.Font = new System.Drawing.Font("Consolas", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSubtract.Location = new System.Drawing.Point(146, 145);
            this.btnSubtract.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnSubtract.Name = "btnSubtract";
            this.btnSubtract.Size = new System.Drawing.Size(116, 39);
            this.btnSubtract.TabIndex = 5;
            this.btnSubtract.Text = "Subtract";
            this.btnSubtract.UseVisualStyleBackColor = true;
            this.btnSubtract.Click += new System.EventHandler(this.btnSubtract_Click);
            // 
            // btnMultiply
            // 
            this.btnMultiply.Font = new System.Drawing.Font("Consolas", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnMultiply.Location = new System.Drawing.Point(268, 145);
            this.btnMultiply.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnMultiply.Name = "btnMultiply";
            this.btnMultiply.Size = new System.Drawing.Size(116, 39);
            this.btnMultiply.TabIndex = 6;
            this.btnMultiply.Text = "Multiply";
            this.btnMultiply.UseVisualStyleBackColor = true;
            this.btnMultiply.Click += new System.EventHandler(this.btnMultiply_Click);
            // 
            // btnDivide
            // 
            this.btnDivide.Font = new System.Drawing.Font("Consolas", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnDivide.Location = new System.Drawing.Point(389, 145);
            this.btnDivide.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnDivide.Name = "btnDivide";
            this.btnDivide.Size = new System.Drawing.Size(116, 39);
            this.btnDivide.TabIndex = 7;
            this.btnDivide.Text = "Divide";
            this.btnDivide.UseVisualStyleBackColor = true;
            this.btnDivide.Click += new System.EventHandler(this.btnDivide_Click);
            // 
            // textAnswer
            // 
            this.textAnswer.Font = new System.Drawing.Font("Consolas", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textAnswer.Location = new System.Drawing.Point(268, 222);
            this.textAnswer.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.textAnswer.Name = "textAnswer";
            this.textAnswer.ReadOnly = true;
            this.textAnswer.Size = new System.Drawing.Size(237, 32);
            this.textAnswer.TabIndex = 9;
            // 
            // lblAnswer
            // 
            this.lblAnswer.AutoSize = true;
            this.lblAnswer.Font = new System.Drawing.Font("Consolas", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAnswer.Location = new System.Drawing.Point(17, 228);
            this.lblAnswer.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lblAnswer.Name = "lblAnswer";
            this.lblAnswer.Size = new System.Drawing.Size(84, 26);
            this.lblAnswer.TabIndex = 8;
            this.lblAnswer.Text = "Answer";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(516, 280);
            this.Controls.Add(this.textAnswer);
            this.Controls.Add(this.lblAnswer);
            this.Controls.Add(this.btnDivide);
            this.Controls.Add(this.btnMultiply);
            this.Controls.Add(this.btnSubtract);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.textInput2);
            this.Controls.Add(this.textInput1);
            this.Controls.Add(this.lblInput2);
            this.Controls.Add(this.lblInput1);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "Form1";
            this.Text = "Demo Calculator Windows Forms";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblInput1;
        private System.Windows.Forms.Label lblInput2;
        private System.Windows.Forms.TextBox textInput1;
        private System.Windows.Forms.TextBox textInput2;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnSubtract;
        private System.Windows.Forms.Button btnMultiply;
        private System.Windows.Forms.Button btnDivide;
        private System.Windows.Forms.TextBox textAnswer;
        private System.Windows.Forms.Label lblAnswer;
    }
}

