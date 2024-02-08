# Directory Exchange Protocol (DXP) Specification

|             |                          |
| :---------- | :----------------------- |
| Status      | Draft                    |
| Author      | Potsawat Thinkanwatthana |
| Created at  | 2024-02-04               |
| Modified at | 2024-02-08               |

## Abstract

The Directory Exchange Protocol (DXP) is a stateless application-level protocol
for reading, exchanging, and forming directory trees. This document describes
the overall architecture of DXP. In this definition are core protocol elements
and the "dxp" Uniform Resource Identifier (URI) schemes.

## Copyright Notice

```
MIT License

Copyright (c) 2024 Potsawat Thinkanwatthana

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## Introduction

### Purpose

The Directory Exchange Protocol (DXP) is a stateless, application-level,
request/response protocol that enables exchanging of directory tree structure
information through the Internet. Data is transfered in the format that allows
the recipient to replicate the source directory while preserving its relative
metadata and contents. Reading the source directory tree is done top-down
without following extra-tree soft links.

## Terminology and Core Concepts

### Eng and Chang

The source directory tree is called "Eng". The target directory tree is called
"Chang". This is to distinguish the term "source" as in "source address"
from the term "source" as in "source directory", avoiding ambiguilty.

### Cookie

DXP is a stateless protocol that uses "cookie" to remember stateful information
namely connection information...

### Token

...

### Connections, Senders, and Recipients

DXP is a protocol that operates over a reliable transport- or session-layer
"connection".

A DXP "sender" is a program that establishes a connection to the recipient
for the purpose of sending one or more DXP requests. A DXP "recipient" is a program
that accepts connections in order to process DXP requests by sending DXP
responses.
...

### Tidbits

DXP is a stateless request/response protocol for exchanging "tidbits" across
a connection. The terms "sender" and "recipient" refer to any implementation
that sends or receives a given tidbit, respectively.
...

### User Agents

...

### Example Tidbit Exchange

The following illustrates a typical DXP tidbit exchange for a PUSH request
on the URI "dxp://example.com/usr/local/lib/ldxp":

Request:

```
PUSH ldxp
DXP-Version: 1.0.0
Date: 2024-02-04T19:50:00+07:00
From: localhost
To: example.com
Cookie: somecookie
Cookie-Expire: 2024-02-04T20:50:00+07:00

```

Response:

```
1000 ACCEPTED
DXP-version: 1.0.0
Date: 2024-02-04T19:50:30+07:00
From: localhost
To: example.com
Cookie: somecookie

```

## Methods

| Method Name | Description                  |
| :---------- | :--------------------------- |
| `PUSH`      | Send a directory tree        |
| `PULL`      | Receive a directory tree     |
| `POLL`      | Reply to start operation     |
| `PICK`      | Get next directory tree node |

...

## Response Status Codes

### Response Status Code Classes

| Status Code Range          | Class                                                                  |
| :------------------------- | :--------------------------------------------------------------------- |
| $[1, 255] \cup [256, 999]$ | Error (GNU C library exit status values and DXP reserved status codes) |
| $[1000, 1999]$             | Request-response                                                       |
| $[2000, 2999]$             | Operation                                                              |

### Predefined Response Status Codes

| Status Code | Status Name      | Meaning                                    |
| ----------- | ---------------- | ------------------------------------------ |
| `0`         | `OK`             | The prior query processing status is fine. |
| `1000`      | `ACCEPTED`       | The request has been accepted.             |
| `1001`      | `DECLINED`       | The request has been declined.             |
| `1002`      | `COOKIE EXPIRED` | The cookie in request has expired.         |
| `2000`      | `DONE`           | There are no more nodes to `PICK`.         |
| `2001`      | `MORE`           | There is at least one more node to `PICK`. |

The exit status code range $[1, 999]$ is defined based on the following:

- `1` through `255`, follows the GNU C library exit status values (aside from `0`)[^1]
- `256` through `999` DXP reserved status codes

## DXP Connections

...

[^1]: https://www.gnu.org/software/libc/manual/html_node/Exit-Status.html,  
        https://www.gnu.org/software/libc/manual/html_node/Error-Codes.html
