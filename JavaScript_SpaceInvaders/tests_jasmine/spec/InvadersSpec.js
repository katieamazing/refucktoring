//https://code.tutsplus.com/tutorials/testing-your-javascript-with-jasmine--net-21229

function usualMockDict() {
  var mockScreen = {};
  var mockCanvas = {
    getContext: jasmine.createSpy('canvas.getContext').and.returnValue(mockScreen),
    width: 310,
    height: 310
  };
  mockScreen.canvas = mockCanvas;
  mockScreen.clearRect = jasmine.createSpy('screen.clearRect');
  mockScreen.fillRect = jasmine.createSpy('screen.fillRect');
  var mockSound = {
    load: jasmine.createSpy('sound.load'),
    play: jasmine.createSpy('sound.play'),
  };
  var mockDocument = {
    getElementById: jasmine.createSpy('document.getElementById')
      .and.callFake(function (id) {
          if (id == 'screen') {
            return mockCanvas;
          } else if (id == 'shoot-sound') {
            return mockSound;
          }
      })
  };
  var mockWindow = {
    requestAnimationFrame: jasmine.createSpy('window.requestAnimationFrame')
  };
  return {
    screen: mockScreen,
    canvas: mockCanvas,
    document: mockDocument,
    window: mockWindow
  };
}

describe ( 'Space Invaders game', function () {
  it('instantiating a new game calls document.getElementById', function () {
    var mocks = usualMockDict();
    var testGame = new PubGame(mocks.document, mocks.window);
    expect(mocks.document.getElementById.calls.any()).toEqual(true);
  });
  it('instantiating a new game calls screen.getContext', function () {
    var mocks = usualMockDict();
    var testGame = new PubGame(mocks.document, mocks.window);
    expect(mocks.canvas.getContext.calls.any()).toEqual(true);
  });
  it('instantiates 25 bodies', function () {
    var mocks = usualMockDict();
    var testGame = new PubGame(mocks.document, mocks.window);
    expect(testGame.bodies.length).toEqual(25);
  });
  it('requestAnimationFrame to be called once', function () {
    var mocks = usualMockDict();
    var testGame = new PubGame(mocks.document, mocks.window);
    expect(mocks.window.requestAnimationFrame.calls.count()).toEqual(1);
  });
  it('Player moves when key is down', function () {
    var mocks = usualMockDict();
    var testGame = new PubGame(mocks.document, mocks.window);
    var testPlayer = testGame.bodies[24];
    spyOn(testPlayer.keyboarder, "isDown").and.callFake(function (keyCode) {
      return keyCode == 37;
    });
    testPlayer.update();
    expect(testPlayer.center.x).toEqual(153);
  });
  it('Player shoots', function () {
    var mocks = usualMockDict();
    var testGame = new PubGame(mocks.document, mocks.window);
    var testPlayer = testGame.bodies[24];
    spyOn(testPlayer.keyboarder, "isDown").and.callFake(function (keyCode) {
      return keyCode == 32;
    });
    testPlayer.update();
    expect(testGame.bodies.length).toBeGreaterThan(25);
  });
  it('Player shoots bullets', function () {
    var mocks = usualMockDict();
    var testGame = new PubGame(mocks.document, mocks.window);
    var testPlayer = testGame.bodies[24];
    spyOn(testPlayer.keyboarder, "isDown").and.callFake(function (keyCode) {
      return keyCode == 32;
    });
    testPlayer.update();
    var bullet = testGame.bodies[25];
    expect(bullet.size.x).toEqual(3);
    expect(bullet.size.y).toEqual(3);
  });
  it('Test can shoot down all the invaders', function () {
    var mocks = usualMockDict();
    var testGame = new PubGame(mocks.document, mocks.window);
    var collision = jasmine.createSpy('collision');
    for (var i = 0; i < 24; i++) {
      var x = 35 + (i % 8) * 30;
      var y = 35 + (i % 3) * 30;
      testGame.bodies.push({
        center: { x: x, y: y },
        size: { x: 3, y: 3 },
        collision: collision
      });
    }
    expect(collision.calls.count()).toEqual(0);
    testGame.update();
    expect(collision.calls.count()).toEqual(24);
    expect(testGame.bodies.length).toEqual(25);
  });
  it('Test can shoot the player', function () {
    var mocks = usualMockDict();
    var testGame = new PubGame(mocks.document, mocks.window);
    var collision = jasmine.createSpy('collision');
    testGame.bodies.push({
      center: { x: 155, y: 275 },
      size: { x: 3, y: 3 },
      collision: collision
    });
    expect(collision.calls.count()).toEqual(0);
    testGame.update();
    expect(collision.calls.count()).toEqual(1);
    expect(testGame.bodies.length).toEqual(25);
  });

});
