using System;

class Invoice {
  // variables
  private string pNumber;
  private string pDescription;
  private int pQuantity;
  private int pPrice;
  private int total;

  // constructor
  public Invoice() {}
  // setters
  void setNum(string number) {
    pNumber = number;
  }
  void setDes(string description) {
    pDescription = description;
  }
  void setPrice(int price) {
    pPrice = price;
  }
  void setQuant(int quant) {
    pQuantity = quant;
  }

  // getters
  string getNum() {
    return pNumber;
  }
  string getDes() {
    return pDescription;
  }
  int getPrice() {
    return pPrice;
  }
  int getQuant() {
    return pQuantity;
  }

  // final invoice total
  int getInvoice() {
    if (pQuantity < 0) {
      pQuantity = 0;
    }
    if (pPrice < 0) {
      pPrice = 0;
    }
    total = pPrice * pQuantity;
    return total;
  }

  // main
  static void Main(string[] args) {
    int price = 0;
    int quant = 0;
    int result = 0;
    string desc;
    string num;

    Console.WriteLine("Enter description: ");
    desc = Console.ReadLine();
    Console.WriteLine("Enter item number: ");
    num = Console.ReadLine();
    Console.WriteLine("Enter quantity: ");
    quant = Convert.ToInt32(Console.ReadLine());
    Console.WriteLine("Enter price: ");
    price = Convert.ToInt32(Console.ReadLine());

    Invoice invoice = new Invoice();
    invoice.setDes(desc);
    invoice.setNum(num);
    invoice.setPrice(price);
    invoice.setQuant(quant);

    result = invoice.getInvoice();

    Console.WriteLine("Total cost of {0} {1}s (item {2}) is {3}", invoice.getQuant(),
                      invoice.getDes(), invoice.getNum(), result);
  }
}
