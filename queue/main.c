#include <stdio.h>
#include <assert.h>
#include "queue.h"

int main()
{
    Queue q;
    QueueResult result;

    /* Create a queue of size 3 */
    q = queue_new(3);

    /* ---------------- INITIAL STATE ---------------- */

    assert(queue_empty(&q));
    assert(!queue_full(&q, &result));

    printf("Queue initially empty: PASS\n");


    /* ---------------- ADD 10 ---------------- */

    queue_add(&q, 10, &result);

    assert(result.status == QUEUE_OK);
    assert(q.count == 1);

    printf("Added 10: PASS\n");


    /* ---------------- ADD 20 ---------------- */

    queue_add(&q, 20, &result);

    assert(result.status == QUEUE_OK);
    assert(q.count == 2);

    printf("Added 20: PASS\n");


    /* ---------------- ADD 30 ---------------- */

    queue_add(&q, 30, &result);

    assert(result.status == QUEUE_OK);
    assert(q.count == 3);

    assert(queue_full(&q, &result));
    assert(result.status == QUEUE_FULL);

    printf("Added 30 - queue full: PASS\n");


    /* ---------------- ADD WHEN FULL ---------------- */

    queue_add(&q, 40, &result);

    assert(result.status == QUEUE_FULL);
    assert(q.count == 3);

    printf("Add when full rejected: PASS\n");


    /* ---------------- REMOVE 10 ---------------- */

    queue_remove(&q, &result);

    assert(result.status == QUEUE_OK);
    assert(result.data == 10);
    assert(q.count == 2);

    printf("Removed 10: PASS\n");


    /* ---------------- REMOVE 20 ---------------- */

    queue_remove(&q, &result);

    assert(result.status == QUEUE_OK);
    assert(result.data == 20);
    assert(q.count == 1);

    printf("Removed 20: PASS\n");


    /* ---------------- ADD 40 (WRAP AROUND) ---------------- */

    queue_add(&q, 40, &result);

    assert(result.status == QUEUE_OK);
    assert(q.count == 2);

    printf("Added 40 using wrap-around: PASS\n");


    /* ---------------- REMOVE 30 ---------------- */

    queue_remove(&q, &result);

    assert(result.status == QUEUE_OK);
    assert(result.data == 30);
    assert(q.count == 1);

    printf("Removed 30: PASS\n");


    /* ---------------- REMOVE 40 ---------------- */

    queue_remove(&q, &result);

    assert(result.status == QUEUE_OK);
    assert(result.data == 40);
    assert(q.count == 0);

    assert(queue_empty(&q));

    printf("Removed 40 - queue empty: PASS\n");


    /* ---------------- REMOVE WHEN EMPTY ---------------- */

    queue_remove(&q, &result);

    assert(result.status == QUEUE_EMPTY);
    assert(q.count == 0);

    printf("Remove from empty rejected: PASS\n");


    printf("\nAll tests passed!\n");

    return 0;
}
