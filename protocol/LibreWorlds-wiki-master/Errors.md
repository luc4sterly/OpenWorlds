Some errors that can be thrown by SESSINIT property #4, the only property of SESSEXIT, and internally within the client in some circumstances.

0 and below are invalid, numbers not on the table are valid and give a message "Login error #" + the number.

| Number | Name | Error message | Notes |
| --- | --- | --- | --- |
| 1 | NAK_BAD_USER | Illegal user name.  Please enter a user name that is 2 to 16 alpha & numeric characters long. | |
| 2 | NAK_MAX_ORDINARY | Sorry, the world is full.  Please try again in a few minutes. | |
| 3 | NAK_MAX_PRIORITY | Sorry, the world is full of priority users. | |
| 4 | | | AssertionError! (Crash?) |
| 5 | NAK_FATAL | TBD | Retries |
| 6 | NAK_BAD_PROTOCOL | TBD | |
| 7 | NAK_BAD_CLIENTSW | TBD | |
| 8 | | | AssertionError! (Crash?) |
| 9 | NAK_BAD_SERIAL | TBD | |
| 10 | NAK_TAKEN_SERIAL | TBD | |
| 11 | NAK_TAKEN_USER | TBD | |
| 12 | NAK_NO_SUCH_USER | TBD | |
| 13 | NAK_BAD_PASSWORD | TBD | |
| 14 | NAK_BAD_ACCOUNT | TBD | |
| 15 | NAK_NOT_LOGGEDON | TBD | |
| 16 | NAK_BAD_IPADDRESS | TBD | |
| 17 | NAK_LOGGEDON | TBD | |
| 21 | | The set of rooms you are in are quite full. Please wait several minutes and try again. | | |
| 100-103 | NAK_UNEXPECTED | TBD | Retries |
| 104-107 | NAK_UNREACHABLE | TBD | Retries |
| 200 | | Connected. | "Status" |
| 201 | | Shutting down server. | "Status" |
| 202 | | Automatically attempting to reconnect. | "Status" |
| 203 | | Server has disconnected normally. | "Status" |
| 204 | | Server has disconnected abnormally. | "Status" |
| 205 | | Going into single user mode. | "Status" |