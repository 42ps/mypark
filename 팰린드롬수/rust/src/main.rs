use std::{error::Error as StdErr, io::Read};

fn main() {
    let palindromes = input().expect("Input Error");

    for p in palindromes {
        if p == "0" {
            break;
        }

        if is_palindromes(&p) {
            println!("yes")
        } else {
            println!("no")
        };
    }
}

fn is_palindromes(s: &str) -> bool {
    let n = s.len() / 2;

    for i in 0..n {
        let b = s.as_bytes();
        if b[i] != b[s.len() - 1 - i] {
            return false;
        }
    }
    true
}

fn input() -> Result<Vec<String>, Box<dyn StdErr>> {
    let mut buf = String::new();

    std::io::stdin().read_to_string(&mut buf)?;

    Ok(buf
        .split_ascii_whitespace()
        .map(|s| s.to_string())
        .collect::<Vec<String>>())
}
