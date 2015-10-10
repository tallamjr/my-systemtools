use std::env;
use std::fs;

fn main()
{    
    let args: Vec<_> = env::args().collect();
    if args.len() == 3
    {
        let input = ::std::env::args().nth(1).unwrap();
        println!("input: {}", input);
        let output = ::std::env::args().nth(2).unwrap();
        println!("output: {}", output);
        fs::copy(input, output);
    }
}