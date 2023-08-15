# qc

Quick Crawl is a simple zero-configuration local web or file system crawler.
It simply attempts to find all possible links it can discover and dumps the resulting files to stdout.

## Table of content

- [Installation](#Installation)
- [Usage](#Usage)
- [License](#License)
- [Contributing](#Contributing)
- [TODO](#TODO)

## Installation

To build this program you will require a recent C compiler, premake, `libargtable2` and `libcmocka` for unit tests.

```sh
premake gmake # to build gnu make file 
make # to compile all targets 
```

## Usage

1) Rename `qc` to the project's name in all files and folders 

## License

This program is distributed under the terms of the MIT License.

## Contributing

## TODO
- Allow file system crawling
- Allow http crawling
- Filter and tag files based on
    - mime type
    - file signatures 
    - keywords
    - data snippets
    - path
