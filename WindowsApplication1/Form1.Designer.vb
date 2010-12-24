<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.StateText = New System.Windows.Forms.TextBox
        Me.B_Login = New System.Windows.Forms.Button
        Me.B_Logout = New System.Windows.Forms.Button
        Me.PhoneNum = New System.Windows.Forms.TextBox
        Me.B_Dial = New System.Windows.Forms.Button
        Me.B_Answer = New System.Windows.Forms.Button
        Me.B_Hangup = New System.Windows.Forms.Button
        Me.SuspendLayout()
        '
        'StateText
        '
        Me.StateText.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(204, Byte))
        Me.StateText.Location = New System.Drawing.Point(22, 32)
        Me.StateText.Name = "StateText"
        Me.StateText.ReadOnly = True
        Me.StateText.Size = New System.Drawing.Size(145, 29)
        Me.StateText.TabIndex = 0
        '
        'B_Login
        '
        Me.B_Login.Location = New System.Drawing.Point(183, 32)
        Me.B_Login.Name = "B_Login"
        Me.B_Login.Size = New System.Drawing.Size(61, 29)
        Me.B_Login.TabIndex = 1
        Me.B_Login.Text = "Login"
        Me.B_Login.UseVisualStyleBackColor = True
        '
        'B_Logout
        '
        Me.B_Logout.Location = New System.Drawing.Point(250, 32)
        Me.B_Logout.Name = "B_Logout"
        Me.B_Logout.Size = New System.Drawing.Size(59, 29)
        Me.B_Logout.TabIndex = 1
        Me.B_Logout.Text = "Logout"
        Me.B_Logout.UseVisualStyleBackColor = True
        '
        'PhoneNum
        '
        Me.PhoneNum.Font = New System.Drawing.Font("Courier New", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(204, Byte))
        Me.PhoneNum.Location = New System.Drawing.Point(22, 84)
        Me.PhoneNum.Name = "PhoneNum"
        Me.PhoneNum.Size = New System.Drawing.Size(145, 26)
        Me.PhoneNum.TabIndex = 2
        '
        'B_Dial
        '
        Me.B_Dial.Location = New System.Drawing.Point(183, 84)
        Me.B_Dial.Name = "B_Dial"
        Me.B_Dial.Size = New System.Drawing.Size(126, 26)
        Me.B_Dial.TabIndex = 3
        Me.B_Dial.Text = "Dial"
        Me.B_Dial.UseVisualStyleBackColor = True
        '
        'B_Answer
        '
        Me.B_Answer.Location = New System.Drawing.Point(22, 136)
        Me.B_Answer.Name = "B_Answer"
        Me.B_Answer.Size = New System.Drawing.Size(145, 35)
        Me.B_Answer.TabIndex = 4
        Me.B_Answer.Text = "Answer"
        Me.B_Answer.UseVisualStyleBackColor = True
        '
        'B_Hangup
        '
        Me.B_Hangup.Location = New System.Drawing.Point(183, 136)
        Me.B_Hangup.Name = "B_Hangup"
        Me.B_Hangup.Size = New System.Drawing.Size(126, 35)
        Me.B_Hangup.TabIndex = 4
        Me.B_Hangup.Text = "Hang Up"
        Me.B_Hangup.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(321, 193)
        Me.Controls.Add(Me.B_Hangup)
        Me.Controls.Add(Me.B_Answer)
        Me.Controls.Add(Me.B_Dial)
        Me.Controls.Add(Me.PhoneNum)
        Me.Controls.Add(Me.B_Logout)
        Me.Controls.Add(Me.B_Login)
        Me.Controls.Add(Me.StateText)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents StateText As System.Windows.Forms.TextBox
    Friend WithEvents B_Login As System.Windows.Forms.Button
    Friend WithEvents B_Logout As System.Windows.Forms.Button
    Friend WithEvents PhoneNum As System.Windows.Forms.TextBox
    Friend WithEvents B_Dial As System.Windows.Forms.Button
    Friend WithEvents B_Answer As System.Windows.Forms.Button
    Friend WithEvents B_Hangup As System.Windows.Forms.Button

End Class
