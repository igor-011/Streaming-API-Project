import React, { useEffect } from 'react';

export function FetchYouTubeTrailerUrl({ item, setSelectedTrailerUrl }) {
  const apiKey = 'AIzaSyD7av-Pezo7-pOjWdReE-EjlNLKoi61R4M';

  useEffect(() => {
    function fetchTrailerUrl() {
      const searchQuery = `${item.title} trailer`;
      const url = `https://www.googleapis.com/youtube/v3/search?part=snippet&q=${encodeURIComponent(
        searchQuery
      )}&maxResults=1&type=video&key=${apiKey}`;

      fetch(url)
        .then((response) => response.json())
        .then((data) => {
          const trailer = data.items[0];
          if (trailer) {
            const videoId = trailer.id.videoId;
            const trailerUrl = `https://www.youtube.com/watch?v=${videoId}`;
            setSelectedTrailerUrl(trailerUrl);
          } else {
            console.log(`No ${item.title} trailer found.`);
          }
        })
        .catch((error) => {
          console.error('Error fetching trailer:', error);
        });
    }

    fetchTrailerUrl();
  }, [item, setSelectedTrailerUrl]);

  return <div>{item.title} Trailer</div>;
}

export default function TrailerComponent({ trailerUrl }) {
  return (
    <div>
      <h2>Trailer Component</h2>
      <iframe
        width="560"
        height="315"
        src={trailerUrl}
        title="Trailer"
        frameBorder="0"
        allowFullScreen
      ></iframe>
    </div>
  );
}






import React, { useEffect } from 'react';

export function FetchYouTubeTrailerUrl({ item, setSelectedTrailerUrl }) {
  const apiKey = 'AIzaSyD7av-Pezo7-pOjWdReE-EjlNLKoi61R4M';

  useEffect(() => {
    function fetchTrailerUrl() {
      const searchQuery = `${item.title} trailer`;
      const url = `https://www.googleapis.com/youtube/v3/search?part=snippet&q=${encodeURIComponent(
        searchQuery
      )}&maxResults=1&type=video&key=${apiKey}`;

      fetch(url)
        .then((response) => response.json())
        .then((data) => {
          const trailer = data.items[0];
          if (trailer) {
            const videoId = trailer.id.videoId;
            const trailerUrl = `https://www.youtube.com/watch?v=${videoId}`;
            setSelectedTrailerUrl(trailerUrl);
          } else {
            console.log(`No ${item.title} trailer found.`);
          }
        })
        .catch((error) => {
          console.error('Error fetching trailer:', error);
        });
    }

    fetchTrailerUrl();
  }, [item, setSelectedTrailerUrl]);

  return <div>{item.title} Trailer</div>;
}

export default function TrailerComponent({ trailerUrl }) {
  return (
    <div>
      <h2>Trailer Component</h2>
      <iframe
        width="560"
        height="315"
        src={trailerUrl}
        title="Trailer"
        frameBorder="0"
        allowFullScreen
      ></iframe>
    </div>
  );
}