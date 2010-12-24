Public Class Form1
    Dim WithEvents ph As YateComServerLib.YatePhone
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        ph = CreateObject("YATE.Phone")
        ph.Protocol = "sip"
        ph.Username = "299"
        ph.Password = "1998"
        ph.Domain = "voip.ctm.ru"
        ph.Server = "192.168.1.44"

        StateText.Text = ph.State
    End Sub
    Private Sub PhoneStateChange(ByVal NewState As YateComServerLib.EnumYatePhoneState) Handles ph.OnStateChange
        StateText.Text = ph.State
    End Sub

    Private Sub B_Login_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles B_Login.Click
        ph.Login()
    End Sub

    Private Sub B_Logout_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles B_Logout.Click
        ph.Logout()
    End Sub

    Private Sub B_Dial_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles B_Dial.Click
        ph.Dial(PhoneNum.Text)
    End Sub

    Private Sub B_Answer_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles B_Answer.Click
        ph.Answer()
    End Sub

    Private Sub B_Hangup_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles B_Hangup.Click
        ph.Hangup()
    End Sub
End Class
