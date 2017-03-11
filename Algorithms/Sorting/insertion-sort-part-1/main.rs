use std::io;
use std::io::Write;

fn read_line(stdin: &mut io::Stdin) -> String
{
  let mut input = String::new();
  match stdin.read_line(&mut input) {
    Ok(n) => {
      input
    }
    Err(err) => panic!("Error while reading line: {}", err)
  }
}

fn write_line(stdout: &mut io::Stdout, output: &String)
{
  match stdout.write_fmt(format_args!("{}", output)) {
    Ok(n) => return,
    Err(err) => panic!("Error while writing line: {}", err)
  }
}

fn main()
{
  let mut stdin  = io::stdin();
  let mut stdout = io::stdout();

  //let size: usize = usize::from_str_radix(read_line(stdin), 10);
  //write_line(size.to_string());
}

