use std::error::Error;
use std::fs;
use std::env;

pub struct Config {
    pub query: String,
    pub filename: String,
    pub case_sensitive: bool,
}

pub fn run(config: Config) -> Result<(), Box<dyn Error>> {
    let contents = fs::read_to_string(config.filename)?;
    
    let results = if config.case_sensitive {
        search(&config.query, &contents)
    }else {
        search_case_insensitive(&config.query, &contents)
    };

    // for line in search(&config.query, &contents) {
    //     println!("{}", line);
    // }
    for line in results {
        println!("{}", line);
    }

    Ok(())
}

impl Config {
    //迭代器 迭代的过程中会修改自己的状态
    pub fn new(mut args: std::env::Args) -> Result<Config, &'static str> {
        if args.len() < 3 {
            return Err("not enough arguments");
        }

        //clone会引起性能的损耗
        // let query = args[1].clone();
        // let filename = args[2].clone();

        //利用迭代器进行修改
        args.next(); //返回值option option处理通过match
        let query = match args.next(){
            Some(arg) => arg,
            None => return Err("didn`t get a query string"),
        };
        let filename = match args.next(){
            Some(arg) => arg,
            None => return Err("didn`t get a filename string"),
        };

        let case_sensitive = 
                env::var("CASE_INSENSITIVE").is_err();

        Ok(Config { query, filename ,case_sensitive})
    }
}

pub fn search<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    // let mut results = Vec::new();

    // for line in contents.lines() {
    //     if line.contains(query) {
    //         results.push(line);
    //     }
    // }
    // results

    //通过迭代器 filter进行修改
    contents.lines()
        .filter(|line| line.contains(query))
        .collect()
}

pub fn search_case_insensitive<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    let mut results = Vec::new();

    let query = query.to_lowercase();

    for line in contents.lines() {
        if line.to_lowercase().contains(&query) {
            results.push(line);
        }
    }
    results
}

//编写测试
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn case_sensitive() {
        let query = "And";

        let contents = "\
        ull f sleep And ndding by the f
        ire, take dwn this bk";

        assert_eq!(
            vec!["ull f sleep And ndding by the f"],
            search(query, contents)
        );
    }

    #[test]
    fn case_insensitive() {
        let query = "and";

        let contents = "\
        ull f sleep And ndding by the f
        ire, take dwn this bk";

        assert_eq!(
            vec!["ull f sleep And ndding by the f"],
            search_case_insensitive(query, contents)
        );
    }
}
