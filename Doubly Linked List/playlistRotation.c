// You are developing a music playlist application, and one of the key features you're implementing is the ability for users to rotate their playlists. This rotation allows users to keep their playlists fresh by shifting songs by a specified number of positions while maintaining the order of their favorite tracks.

// To achieve this, you need to implement a function that takes a doubly linked list representing the playlist and an integer k representing the number of positions to rotate. The function should return the new head of the rotated playlist.

// Note:

// Utilize the provided boilerplate code or develop your own, ensuring it aligns with the given input and output formats.
// Minimize extraneous print statements; your output should match the specified format.
// Input Format

// First Line consist of a number N showing the number of songs
// Second Line consist of the songs space separated
// The line consist of k: An integer representing the number of positions to rotate. It can be positive or negative. A positive value means rotating songs to the right (clockwise), and a negative value means rotating songs to the left (counter-clockwise).
// Constraints

// -100

// Output Format

// The program will print the space separated names of rotated songs playlist.

// Sample Input 0

// 5
// Song_a Song_b Song_c Song_d Song_e
// -2
// Sample Output 0

// Song_c Song_d Song_e Song_a Song_b
// Sample Input 1

// 5
// Song_a Song_b Song_c Song_d Song_e
// 2
// Sample Output 1

// Song_d Song_e Song_a Song_b Song_c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char title[100];
    struct Song *prev;
    struct Song *next;
};

struct Song *createSong(const char *title)
{
    struct Song *newSong = (struct Song *)malloc(sizeof(struct Song));
    strcpy(newSong->title, title);
    newSong->prev = NULL;
    newSong->next = NULL;
    return newSong;
}

struct Song *createPlaylistFromArray(char *songTitles[], int numSongs)
{
    // create a linked list of songs from the array of song titles
    struct Song *head = createSong(songTitles[0]);
    struct Song *current = head;
    for (int i = 1; i < numSongs; i++)
    {
        struct Song *newSong = createSong(songTitles[i]);
        current->next = newSong;
        newSong->prev = current;
        current = current->next;
    }
    return head;
}

struct Song *rotatePlaylist(struct Song *head, int k)
{
    // Write your code here
    struct Song *current = head;
    struct Song *tail = NULL;
    while (current->next)
    {
        current = current->next;
    }
    tail = current;
    if (k > 0)
    {
        for (int i = 0; i < k; i++)
        {
            tail->next = head;
            head->prev = tail;
            head = tail;
            tail = tail->prev;
            tail->next = NULL;
            head->prev = NULL;
        }
    }
    else
    {
        for (int i = 0; i < abs(k); i++)
        {
            tail->next = head;
            head->prev = tail;
            head = head->next;
            head->prev = NULL;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    return head;
}

// Helper function to print the playlist
void printPlaylist(struct Song *head)
{
    struct Song *current = head;
    while (current)
    {
        printf("%s ", current->title);
        current = current->next;
    }
}

int main()
{
    int numSongs;
    scanf("%d", &numSongs);

    char *songTitles[numSongs];
    for (int i = 0; i < numSongs; i++)
    {
        songTitles[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", songTitles[i]);
    }

    struct Song *playlistHead = createPlaylistFromArray(songTitles, numSongs);

    int k;
    scanf("%d", &k);

    struct Song *rotatedHead = rotatePlaylist(playlistHead, k);

    printPlaylist(rotatedHead);

    // Free dynamically allocated memory for song titles
    for (int i = 0; i < numSongs; i++)
    {
        free(songTitles[i]);
    }

    return 0;
}