#define N 100  /* number of slots in the buffer */
void producer(void)
{
  int item;
  message m;                  /* message buffer */
  while (TRUE) {
    item = produce_item();    /* generate something to put in buffer */
    receive(consumer, &m);    /* wait for an empty to arrive */
    build_message(&m, item);  /* construct a message to send */
    send(consumer, &m);       /* send item to consumer */
  }
}

void consumer(void)
{
  int item, i;
  message m;
  for (i=0; i<N; i++) send(producer, &m);  /* send N empties */
  while (TRUE) {
    receive(producer, &m);    /* get message containing item */
    item = extract_item(&m);  /* extract item from message */
    send(producer, &m);       /* send back empty reply */
    consume_item(item);       /* do something with the item */
  }
}
