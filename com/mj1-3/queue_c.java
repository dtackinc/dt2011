package mj13;

/*..........................................................................
 *..........................................................................*/
public
class
queue_c				
{
  private int m;
  private String command[];
  private int p;
  private int q;
  
/*..........................................................................
 *..........................................................................*/
  queue_c(
    int m)
  {
	this.m = m;
	this.command = new String[m];
	this.p = 0;
	this.q = 0;
  }

/*..........................................................................
 *..........................................................................*/
  public void 
  add(
    String command)
  {
	if (command == null)
	  return;
	if (p == q + m)						// queue full?						*/
	  return;
	this.command[p%m] = command;		// add command to queue
	p++;
  }

/*..........................................................................
 *..........................................................................*/
  public String
  remove()        
  {
	if (p == q)
	  return null;
	return command[(q++)%m];
  }

/*..........................................................................
 *..........................................................................*/
  public int
  size()								// return to queue size
  {
	return p - q;
  }	
} 										/* end class 						*/
