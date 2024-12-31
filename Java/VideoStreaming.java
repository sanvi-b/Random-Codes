import java.util.Scanner;
class Video 
{
    String title;
    String url;
    Video prev;
    Video next;
    public Video(String title, String url) 
    {
        this.title = title;
        this.url = url;
        this.prev = null;
        this.next = null;
    }
}
class VideoStreamingPlatform 
{
    private Video head;
    private Video tail;
    private Video currentVideo;
    public VideoStreamingPlatform() 
    {
        this.head = null;
        this.tail = null;
        this.currentVideo = null;
    }
    public void addVideo(String title, String url) 
    {
        Video newVideo = new Video(title, url);
        if (head == null) 
        {
            head = newVideo;
            tail = newVideo;
        } else {
            tail.next = newVideo;
            newVideo.prev = tail;
            tail = newVideo;
        }
        if (currentVideo == null) 
            currentVideo = head;
    }
    public void playCurrentVideo() 
    {
        if (currentVideo != null) 
        {
            System.out.println("Now playing: " + currentVideo.title);
            System.out.println("URL: " + currentVideo.url);
        } else 
            System.out.println("No video available to play.");
    }
    public void nextVideo() 
    {
        if (currentVideo != null && currentVideo.next != null) 
        {
            currentVideo = currentVideo.next;
            playCurrentVideo();
        } else 
            System.out.println("No next video available.");
    }
    public void previousVideo() 
    {
        if (currentVideo != null && currentVideo.prev != null) 
        {
            currentVideo = currentVideo.prev;
            playCurrentVideo();
        } else 
            System.out.println("No previous video available.");
    }
    public void listVideos() 
    {
        Video current = head;
        while (current != null) 
        {
            System.out.println(current.title);
            current = current.next;
        }
    }
}
public class VideoStreaming 
{
    public static void main(String[] args) 
    {
        VideoStreamingPlatform platform = new VideoStreamingPlatform();
        Scanner scanner = new Scanner (System.in);
        platform.addVideo("Introduction to Java", "https://example.com/java-intro");
        platform.addVideo("Data Structures", "https://example.com/data-structures");
        platform.addVideo("Algorithms", "https://example.com/algorithms");
        System.out.println("\n--- Video Streaming Platform Menu ---");
        System.out.println("1. Add a new video");
        System.out.println("2. Play current video");
        System.out.println("3. Play next video");
        System.out.println("4. Play previous video");
        System.out.println("5. List all videos");
        System.out.println("6. Exit");
        while (true) 
        {
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine();
            switch (choice) 
            {
                case 1:
                    System.out.print("Enter video title: ");
                    String title = scanner.nextLine();
                    System.out.print("Enter video URL: ");
                    String url = scanner.nextLine();
                    platform.addVideo(title, url);
                    System.out.println("Video added successfully.");
                    break;
                case 2:
                    platform.playCurrentVideo();
                    break;
                case 3:
                    platform.nextVideo();
                    break;
                case 4:
                    platform.previousVideo();
                    break;
                case 5:
                    System.out.println("List of all videos:");
                    platform.listVideos();
                    break;
                case 6:
                    System.out.println("Thank you for using the Video Streaming Platform. Goodbye!");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
/* 
 https://example.com/computer-programming 
  OOPs Concepts
  https://example.com/oops-concepts */  