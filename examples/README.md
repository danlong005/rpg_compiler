# Customer Order Thank-You Example

A three-program workflow that demonstrates record-level access (RLA) and the `rpgc.conf` implicit database connection. All three programs use RLA opcodes (READ, CHAIN, UPDATE, WRITE) with no explicit `EXEC SQL CONNECT` required.

## What It Does

| Program | Description |
|---------|-------------|
| `CUST01R` | Reads the orders table for orders placed today, looks up each customer by key, and writes a thank-you message to the messages table |
| `CUST02R` | Reads pending messages, chains to the customers table to get the email address, updates the message with the email, and marks it sent (`status = 'X'`) |
| `CUST03R` | Reads completed messages (`status = 'X'`) and updates the orders table to mark each order as thanked (`thanked = 'Y'`) |

## Tables

```
customers   id, first_name, last_name, email
orders      id, customer_id, placed_at, thanked
messages    id, customer_id, order_id, message, email, status
```

## Prerequisites

- `rpgc` installed and on your PATH (see main README)
- SQLite ODBC driver
  - macOS: `brew install sqliteodbc`
  - Linux: `sudo apt install libsqliteodbc`

## Setup

**1. Create the database and load sample data:**

```bash
sqlite3 /tmp/example.db < examples/setup.sql
```

**2. Configure the database connection.**

`rpgc` looks for a connection string in three places, in priority order:

1. `RPGC_DSN` environment variable
2. `rpgc.conf` in the current directory
3. `~/.rpgc.conf` in your home directory

The home directory option is the most convenient for day-to-day use — set it once and every project picks it up automatically:

```ini
# ~/.rpgc.conf
DB_DSN=Driver={SQLite3};Database=/tmp/example.db;
```

Or use a project-level `rpgc.conf` in the directory where you invoke the compiler:

```ini
# rpgc.conf
DB_DSN=Driver={SQLite3};Database=/tmp/example.db;
```

Or pass it inline as an environment variable for one-off runs:

```bash
export RPGC_DSN="Driver={SQLite3};Database=/tmp/example.db;"
```

## Compile

From the project root:

```bash
rpgc examples/CUST01R.rpgle -o CUST01R
rpgc examples/CUST02R.rpgle -o CUST02R
rpgc examples/CUST03R.rpgle -o CUST03R
```

## Run

Run the programs in order:

```bash
./CUST01R   # queue thank-you messages for today's orders
./CUST02R   # populate email addresses and mark messages sent
./CUST03R   # mark orders as thanked
```

### Expected output

```
$ ./CUST01R
Message queued for Alice Smith
Message queued for Bob Jones

$ ./CUST02R
Email queued for Alice: alice@example.com
Email queued for Bob: bob@example.com

$ ./CUST03R
Order 1 marked as thanked
Order 2 marked as thanked
```

Carol's order from 2024-01-15 is skipped because it was not placed today.
