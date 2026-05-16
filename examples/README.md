# Customer Order Thank-You Example

A three-program workflow that demonstrates record-level access (RLA), embedded SQL, and the `rpgc.conf` implicit database connection.

## What It Does

| Program | Description |
|---------|-------------|
| `CUST01R` | Reads the orders table for orders placed today, looks up each customer, and writes a thank-you message to the messages table |
| `CUST02` | Reads pending messages, fetches the customer email address, updates the message record with the email, and marks it sent (`status = 'X'`) |
| `CUST03R` | Reads completed messages (`status = 'X'`) and updates the orders table to mark each order as thanked (`thanked = 'Y'`) |

## Tables

```
customers   id, first_name, last_name, email
orders      id, customer_id, placed_at, thanked
messages    id, customer_id, order_id, message, email, status
```

## Prerequisites

- `rpgc` built and on your PATH (see main README)
- SQLite ODBC driver
  - macOS: `brew install sqliteodbc`
  - Linux: `sudo apt install libsqliteodbc`

## Setup

**1. Create the database and load sample data:**

```bash
sqlite3 /tmp/example.db < examples/setup.sql
```

**2. Configure the database connection.**

Create `rpgc.conf` in the directory where you will invoke `rpgc`:

```ini
DB_DSN=Driver={SQLite3};Database=/tmp/example.db;
```

Or export it as an environment variable:

```bash
export RPGC_DSN="Driver={SQLite3};Database=/tmp/example.db;"
```

## Compile

```bash
rpgc examples/CUST01R.rpgle   -o CUST01R
rpgc examples/CUST02.sqlrpgle -o CUST02
rpgc examples/CUST03R.rpgle   -o CUST03R
```

## Run

Run the programs in order:

```bash
./CUST01R   # queue thank-you messages for today's orders
./CUST02    # populate email addresses and mark messages sent
./CUST03R   # mark orders as thanked
```

### Expected output

```
$ ./CUST01R
Message queued for Alice Smith
Message queued for Bob Jones

$ ./CUST02
Email queued for Alice: alice@example.com
Email queued for Bob: bob@example.com

$ ./CUST03R
Order 1 marked as thanked
Order 2 marked as thanked
```

Carol's order from 2024-01-15 is not processed because it was not placed today.
