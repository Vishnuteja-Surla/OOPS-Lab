import tkinter

window = tkinter.Tk()

def grade_to_gpa(a):
    if a.upper() == "S":
        return 10
    elif a.upper() == "A":
        return 9
    elif a.upper() == "B":
        return 8
    elif a.upper() == "C":
        return 7
    elif a.upper() == "D":
        return 6
    elif a.upper() == "E":
        return 5
    elif a.upper() == "U" or a.upper() == "W" or a.upper() == "I":
        return 0
    else:
        return '-'

def calculate():
    out5 = tkinter.Label(window, text = "")
    out5.grid(column = 4, row = 7)
    out5.config(text = "")
    g1 = grade_to_gpa(e1.get())*4
    g2 = grade_to_gpa(e2.get())*4
    g3 = grade_to_gpa(e3.get())*3
    g4 = grade_to_gpa(e4.get())*4
    if g1 == '----' or g2 == '----' or g3 == '---' or g4 == '----':
        out5.configure(text = "Invalid")
    else:
        total = g1+g2+g3+g4
        sgp = total/15
        out1 = tkinter.Label(window, text = f"{g1}")
        out1.grid(column = 4, row = 3)
        out2 = tkinter.Label(window, text = f"{g2}")
        out2.grid(column = 4, row = 4)
        out3 = tkinter.Label(window, text = f"{g3}")
        out3.grid(column = 4, row = 5)
        out4 = tkinter.Label(window, text = f"{g4}")
        out4.grid(column = 4, row = 6)
        out5.configure(text = f"{total}")
        out6 = tkinter.Label(window, text = f"{round(sgp,2)}")
        out6.grid(column = 4, row = 8)

window.title("MARKSHEET")
window.geometry('350x250')
name_l = tkinter.Label(window, text = "Name")
name_l.grid(column = 0, row = 0)
name_e = tkinter.Entry(window, width=10)
name_e.grid(column = 1, row = 0)
reg_l = tkinter.Label(window, text = "Reg.No")
reg_l.grid(column = 2, row = 0)
reg_e = tkinter.Entry(window, width=10)
reg_e.grid(column = 3, row = 0)
roll_l = tkinter.Label(window, text = "Roll.No")
roll_l.grid(column = 0, row = 1)
reg_e = tkinter.Entry(window, width=10)
reg_e.grid(column = 1, row = 1)

#Table Entries
h1 = tkinter.Label(window, text = "Srl.No")
h1.grid(column = 0, row = 2)
h2 = tkinter.Label(window, text = "Subject")
h2.grid(column = 1, row = 2)
h3 = tkinter.Label(window, text = "Grade")
h3.grid(column = 2, row = 2)
h4 = tkinter.Label(window, text = "Sub Credit")
h4.grid(column = 3, row = 2)
h5 = tkinter.Label(window, text = "Credit Obtained")
h5.grid(column = 4, row = 2)
subjects = ["CS201", "CS202", "MA201", "EC201"]
sub_credit = ['4','4','3','4']
for i in range(4):
    temp = tkinter.Label(window, text = f"{i+1}")
    temp.grid(column = 0, row = 3+i)
    temp = tkinter.Label(window, text = subjects[i])
    temp.grid(column = 1, row = 3+i)
    temp = tkinter.Label(window, text = sub_credit[i])
    temp.grid(column = 3, row = 3+i)
e1 = tkinter.Entry(window, width=10)
e1.grid(column = 2, row = 3)
e2 = tkinter.Entry(window, width=10)
e2.grid(column = 2, row = 4)
e3 = tkinter.Entry(window, width=10)
e3.grid(column = 2, row = 5)
e4 = tkinter.Entry(window, width=10)
e4.grid(column = 2, row = 6)
tc = tkinter.Label(window, text = "Total credit")
tc.grid(column = 3, row = 7)
sgpa = tkinter.Label(window, text = "SGPA")
sgpa.grid(column = 3, row = 8)

#Button
bt = tkinter.Button(window, text="submit", command = calculate, background='green')
bt.grid(column = 1 , row = 8)
window.mainloop()