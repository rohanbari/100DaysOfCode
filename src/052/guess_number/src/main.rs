use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    const LOWER: u32 = 1;
    const UPPER: u32 = 101;

    println!("=== Guess The Number Game ===");

    // Using Rng trait to generate unique random numbers
    let secret_number = rand::thread_rng().gen_range(LOWER..UPPER);

    loop {
        println!("Please input your guess.");

        // Accepting user input as a string
        let mut guess = String::new();

        // Reading the input, some notables things:
        //   - The parameter  guess  is passed as a mutable-reference
        //   - The variables passed as arguments are considered immutable objects
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        // Trimming the whitespaces, then parsing and handling
        // any possible error that might happen during parse operation
        let guess: u32 = match guess.trim().parse() {
            //  If  match  returns Ok enum variant, then assign it to the value,
            //  otherwise handling the error
            Ok(num) => num,
            Err(_) => {
                println!("The input must be a valid unsigned 4-bytes integer!");
                break;
            }
        };

        println!("You guessed {}", guess);

        // Comparing the  secret_number  with  guess  by using Ordering trait
        match guess.cmp(&secret_number) {
            Ordering::Greater => println!("\tGuessed too high..."),
            Ordering::Less => println!("\tGuessed too low..."),
            Ordering::Equal => {
                println!("\tCORRECT!");
                break;
            }
        };
    }
}
