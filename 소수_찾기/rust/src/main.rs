use std::{error::Error as StdErr, io::Read};

fn main() {
    let numbers = input().expect("Input Error");
    let ans = numbers.iter().filter(|x| is_prime(**x)).count();
    println!("{ans}");
}

fn is_prime(x: usize) -> bool {
    if x == 2 {
        return true;
    }

    if x == 1 || x % 2 == 0 {
        return false;
    }

    let mut i = 3;
    while i * i <= x {
        if x % i == 0 {
            return false;
        }
        i += 2;
    }

    true
}

fn input() -> Result<Vec<usize>, Box<dyn StdErr>> {
    let mut buf = String::new();
    let mut v = Vec::new();

    std::io::stdin().read_to_string(&mut buf)?;

    let mut sp = buf.split_ascii_whitespace();
    sp.next();

    for n in sp {
        let num = n.parse()?;
        v.push(num);
    }

    Ok(v)
}
