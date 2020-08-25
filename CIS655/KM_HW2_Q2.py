import tkinter as tk
from tkinter.filedialog import askopenfilename, asksaveasfilename

# TODO create a type field, possibly 4 (math opeartions, load/store,
# comparisons, jumps/branches

# TODO create list of all available operations: 50

# TODO list of registers

##def type_find(typ):
##    
##
##def op_find(cmd):
##    if cmd == "add":
##        return 

def open_file():
    """Open a file for editing."""
    filepath = askopenfilename(
        filetypes=[("Text Files", "*.txt"), ("All Files", "*.*")]
    )
    if not filepath:
        return
    txt_edit.delete(1.0, tk.END)
    with open(filepath, "r") as input_file:
        text = input_file.read()
        txt_edit.insert(tk.END, text)
    window.title(f"Simple Text Editor - {filepath}")

def save_file():
    """Save the current file as a new file."""
    filepath = asksaveasfilename(
        defaultextension="txt",
        filetypes=[("Text Files", "*.txt"), ("All Files", "*.*")],
    )
    if not filepath:
        return
    with open(filepath, "w") as output_file:
        text = txt_edit.get(1.0, tk.END)
        output_file.write(text)
    window.title(f"Simple Text Editor - {filepath}")

def run_parse():
    u_input = user_input.get()
    #typ, cmd, op1, op2, op3 = user_input.split(" ")
    user_result=u_input
    T = tk.Text(window, height=10, width=30) 
    #T.pack() 
    T.insert(tk.END, user_result) 


window = tk.Tk()
window.title("KM_IDE")
window.rowconfigure(0, minsize=800, weight=1)
window.columnconfigure(1, minsize=800, weight=1)

input_window = tk.Frame(master=window)
user_input = tk.Entry(master=input_window, text="Enter commands")
user_input.grid(row=0, column=0, sticky="e", padx=10)
user_result = tk.Label(master=window)
user_result.grid(row=1, column=0)
btn_convert = tk.Button(master=input_window, command=run_parse)

txt_edit = tk.Text(window)
fr_buttons = tk.Frame(window, relief=tk.RAISED, bd=2)
btn_open = tk.Button(fr_buttons, text="Open", command=open_file)
btn_save = tk.Button(fr_buttons, text="Save As...", command=save_file)
btn_run = tk.Button(fr_buttons, text="Run", command=run_parse)
btn_open.grid(row=0, column=0, sticky="ew", padx=5, pady=5)
btn_save.grid(row=1, column=0, sticky="ew", padx=5, pady=5)
btn_run.grid(row=2, column=0, sticky="ew", padx=5)

fr_buttons.grid(row=0, column=0, sticky="ns")
txt_edit.grid(row=0, column=1, sticky="nsew")

window.mainloop()
