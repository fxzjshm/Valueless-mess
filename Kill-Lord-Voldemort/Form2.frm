VERSION 5.00
Begin VB.Form Form2 
   Caption         =   "Form2"
   ClientHeight    =   6690
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   9480
   LinkTopic       =   "Form2"
   ScaleHeight     =   6690
   ScaleWidth      =   9480
   StartUpPosition =   2  '屏幕中心
   Begin VB.Timer Timer3 
      Interval        =   100
      Left            =   720
      Top             =   0
   End
   Begin VB.Timer Timer2 
      Enabled         =   0   'False
      Interval        =   1500
      Left            =   360
      Top             =   0
   End
   Begin VB.CommandButton Command6 
      BackColor       =   &H00FFFFFF&
      Height          =   1215
      Left            =   6840
      MaskColor       =   &H00FFFFFF&
      Picture         =   "Form2.frx":0000
      Style           =   1  'Graphical
      TabIndex        =   7
      Top             =   5400
      Width           =   1335
   End
   Begin VB.CommandButton Command5 
      BackColor       =   &H00FFFFFF&
      Height          =   1215
      Left            =   4080
      MaskColor       =   &H00FFFFFF&
      Picture         =   "Form2.frx":0817
      Style           =   1  'Graphical
      TabIndex        =   6
      Top             =   5400
      Width           =   1335
   End
   Begin VB.CommandButton Command4 
      BackColor       =   &H00FFFFFF&
      Height          =   1215
      Left            =   1440
      MaskColor       =   &H00FFFFFF&
      Picture         =   "Form2.frx":102E
      Style           =   1  'Graphical
      TabIndex        =   5
      Top             =   5400
      Width           =   1335
   End
   Begin VB.CommandButton Command3 
      BackColor       =   &H00FFFFFF&
      Height          =   1215
      Left            =   6840
      MaskColor       =   &H00FFFFFF&
      Picture         =   "Form2.frx":1845
      Style           =   1  'Graphical
      TabIndex        =   4
      Top             =   3240
      Width           =   1335
   End
   Begin VB.CommandButton Command2 
      BackColor       =   &H00FFFFFF&
      Height          =   1215
      Left            =   4080
      MaskColor       =   &H00FFFFFF&
      Picture         =   "Form2.frx":205C
      Style           =   1  'Graphical
      TabIndex        =   3
      Top             =   3240
      Width           =   1335
   End
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   0
      Top             =   0
   End
   Begin VB.CommandButton Command1 
      BackColor       =   &H00FFFFFF&
      Height          =   1215
      Left            =   1440
      MaskColor       =   &H00FFFFFF&
      Picture         =   "Form2.frx":2873
      Style           =   1  'Graphical
      TabIndex        =   2
      Top             =   3240
      Width           =   1335
   End
   Begin VB.Label Label8 
      BackStyle       =   0  'Transparent
      Caption         =   "0"
      Height          =   495
      Left            =   0
      TabIndex        =   13
      Top             =   5760
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.Label Label7 
      BackStyle       =   0  'Transparent
      Caption         =   "3"
      Height          =   495
      Left            =   600
      TabIndex        =   12
      Top             =   6240
      Visible         =   0   'False
      Width           =   615
   End
   Begin VB.Label Label6 
      BackStyle       =   0  'Transparent
      Caption         =   "0"
      Height          =   495
      Left            =   0
      TabIndex        =   11
      Top             =   6240
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.Label Label5 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   15.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   0
      TabIndex        =   10
      Top             =   1560
      Width           =   4455
   End
   Begin VB.Image Image7 
      Height          =   945
      Left            =   7200
      Picture         =   "Form2.frx":308A
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   720
   End
   Begin VB.Image Image6 
      Height          =   945
      Left            =   4440
      Picture         =   "Form2.frx":415E
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   720
   End
   Begin VB.Image Image5 
      Height          =   945
      Left            =   1800
      Picture         =   "Form2.frx":5232
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   720
   End
   Begin VB.Image Image4 
      Height          =   945
      Left            =   7200
      Picture         =   "Form2.frx":6306
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   720
   End
   Begin VB.Image Image3 
      Height          =   945
      Left            =   4440
      Picture         =   "Form2.frx":73DA
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   720
   End
   Begin VB.Image Image2 
      Height          =   945
      Left            =   1800
      Picture         =   "Form2.frx":84AE
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   720
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   " "
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   72
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1335
      Left            =   3360
      TabIndex        =   9
      Top             =   960
      Width           =   2535
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "黑体"
         Size            =   18
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   4920
      TabIndex        =   8
      Top             =   840
      Width           =   4215
   End
   Begin VB.Image Image10 
      Height          =   960
      Left            =   1800
      Picture         =   "Form2.frx":9582
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Image Image11 
      Height          =   1020
      Left            =   1800
      Picture         =   "Form2.frx":A18E
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   690
   End
   Begin VB.Image Image22 
      Height          =   960
      Left            =   7200
      Picture         =   "Form2.frx":AAEC
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Image Image21 
      Height          =   1020
      Left            =   7200
      Picture         =   "Form2.frx":B6F8
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   690
   End
   Begin VB.Image Image20 
      Height          =   960
      Left            =   4440
      Picture         =   "Form2.frx":C056
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Image Image19 
      Height          =   1020
      Left            =   4440
      Picture         =   "Form2.frx":CC62
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   690
   End
   Begin VB.Image Image18 
      Height          =   960
      Left            =   1800
      Picture         =   "Form2.frx":D5C0
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Image Image17 
      Height          =   1020
      Left            =   1800
      Picture         =   "Form2.frx":E1CC
      Stretch         =   -1  'True
      Top             =   4440
      Visible         =   0   'False
      Width           =   690
   End
   Begin VB.Image Image16 
      Height          =   960
      Left            =   7200
      Picture         =   "Form2.frx":EB2A
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Image Image15 
      Height          =   1020
      Left            =   7200
      Picture         =   "Form2.frx":F736
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   690
   End
   Begin VB.Image Image14 
      Height          =   960
      Left            =   4440
      Picture         =   "Form2.frx":10094
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   675
   End
   Begin VB.Image Image13 
      Height          =   1020
      Left            =   4440
      Picture         =   "Form2.frx":10CA0
      Stretch         =   -1  'True
      Top             =   2280
      Visible         =   0   'False
      Width           =   690
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "：快快点击伏地魔，与我一起主持正义吧！！！！！"
      BeginProperty Font 
         Name            =   "黑体"
         Size            =   15.75
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   4920
      TabIndex        =   1
      Top             =   120
      Width           =   4455
   End
   Begin VB.Image Image9 
      Height          =   1680
      Left            =   3600
      Picture         =   "Form2.frx":115FE
      Top             =   0
      Width           =   1320
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "0"
      BeginProperty Font 
         Name            =   "Arial"
         Size            =   24
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   0
      TabIndex        =   0
      Top             =   840
      Width           =   3615
   End
   Begin VB.Image Image8 
      Height          =   1515
      Left            =   0
      Picture         =   "Form2.frx":1241C
      Top             =   0
      Width           =   3585
   End
   Begin VB.Image Image1 
      Height          =   7665
      Left            =   0
      Picture         =   "Form2.frx":136AD
      Top             =   -960
      Width           =   9450
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
If Label4 = "1" Then
Label1 = Label1 + 1
Label4 = ""
Image10.Visible = False
Image11.Visible = True
Label6 = Label6 + 1
Else
Label7 = Label7 - 1
Image10.Visible = False
Image2.Visible = True
End If
Label8 = 1
End Sub
Private Sub Command2_Click()
If Label4 = "2" Then
Label1 = Label1 + 1
Label4 = ""
Image14.Visible = False
Image13.Visible = True
Label6 = Label6 + 1
Else
Label7 = Label7 - 1
Image14.Visible = False
Image3.Visible = True
End If
Label8 = 1
End Sub
Private Sub Command3_Click()
If Label4 = "3" Then
Label1 = Label1 + 1
Label4 = ""
Image16.Visible = False
Image15.Visible = True
Label6 = Label6 + 1
Else
Label7 = Label7 - 1
Image16.Visible = False
Image4.Visible = True
End If
Label8 = 1
End Sub
Private Sub Command4_Click()
If Label4 = "4" Then
Label1 = Label1 + 1
Label4 = ""
Image18.Visible = False
Image17.Visible = True
Label6 = Label6 + 1
Else
Label7 = Label7 - 1
Image18.Visible = False
Image5.Visible = True
End If
Label8 = 1
End Sub
Private Sub Command5_Click()
If Label4 = "5" Then
Label1 = Label1 + 1
Label4 = ""
Image20.Visible = False
Image19.Visible = True
Label6 = Label6 + 1
Else
Label7 = Label7 - 1
Image20.Visible = False
Image6.Visible = True
End If
Label8 = 1
End Sub
Private Sub Command6_Click()
If Label4 = "6" Then
Label1 = Label1 + 1
Label4 = ""
Image22.Visible = False
Image21.Visible = True
Label6 = Label6 + 1
Else
Label7 = Label7 - 1
Image22.Visible = False
Image7.Visible = True
End If
Label8 = 1
End Sub
Private Sub Form_Load()
Command1.Enabled = False
Command2.Enabled = False
Command3.Enabled = False
Command4.Enabled = False
Command5.Enabled = False
Command6.Enabled = False
Timer1.Enabled = True
End Sub
Private Sub Timer1_Timer()
Select Case Label4.Caption
Case " "
Label4.Caption = "3"
Case "3"
Label4.Caption = "2"
Case "2"
Label4.Caption = "1"
Case "1"
Label4.Caption = "GO"
Case "GO"
Timer1.Enabled = False
Command1.Enabled = True
Command2.Enabled = True
Command3.Enabled = True
Command4.Enabled = True
Command5.Enabled = True
Command6.Enabled = True
Label4.Caption = ""
Label4.Visible = False
Label4.Enabled = False
Timer2.Enabled = True
Label3.Caption = "你还有" & Label7 & "次打错的机会"
Label5.Caption = "距离下次加一次机会还有" & 5 - Label6 & "分"
End Select
End Sub
Private Sub Timer2_Timer()
Image2.Visible = False
Image3.Visible = False
Image4.Visible = False
Image5.Visible = False
Image6.Visible = False
Image7.Visible = False
Image10.Visible = False
Image11.Visible = False
Image13.Visible = False
Image14.Visible = False
Image15.Visible = False
Image16.Visible = False
Image17.Visible = False
Image18.Visible = False
Image19.Visible = False
Image20.Visible = False
Image21.Visible = False
Image22.Visible = False
If Label8 = 0 Then
Label7 = Label7 - 1
End If
Randomize
a = Int(Rnd * 6) + 1
Select Case a
Case 1
Image10.Visible = True
Case 2
Image14.Visible = True
Case 3
Image16.Visible = True
Case 4
Image18.Visible = True
Case 5
Image20.Visible = True
Case 6
Image22.Visible = True
End Select
Print a
Label4 = a
Label8 = 0
End Sub
Private Sub Timer3_Timer()
If Label7 = -1 Then
MsgBox "游戏结束！"
Unload Form2
End If
Label3.Caption = "你还有" & Label7 & "次打错的机会"
Label5.Caption = "距离下次加一次机会还有" & 5 - Label6 & "分"
If Label6 >= 5 Then
Label7 = Label7 + 1
Label6 = Label6 - 5
End If
End Sub
