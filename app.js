/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function (text) {
  const numOfLetterCount = { b: 0, a: 0, l: 0, o: 0, n: 0 };
  Array.from(text).forEach((letter) => {
    if ("balon".includes(letter)) {
      numOfLetterCount[letter]++;
    }
  });
  return Math.min(
    numOfLetterCount["b"],
    numOfLetterCount["a"],
    numOfLetterCount["n"],
    Math.floor(numOfLetterCount["l"] / 2),
    Math.floor(numOfLetterCount["o"] / 2)
  );
};

console.log(maxNumberOfBalloons("balon"));
