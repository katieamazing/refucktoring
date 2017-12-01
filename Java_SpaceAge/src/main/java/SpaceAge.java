public class SpaceAge {
    private Long seconds;

    public SpaceAge(Long seconds) {
        this.seconds = seconds;
    }

    public  SpaceAge(Integer seconds) {
        this.seconds = new Long(seconds);
    }

    public Long getSeconds() {
        return this.seconds;
    }

    public double onEarth() {
        return this.seconds / 31557600.0;
    }

    public double onMercury() {
        return onEarth() / 0.2408467;
    }

    public double onVenus() {
        return onEarth() / 0.61519726;
    }

    public double onMars() {
        return onEarth() / 1.8808158;
    }

    public double onJupiter() {
        return onEarth() / 11.862615;
    }

    public double onSaturn() {
        return onEarth() / 29.447498;
    }

    public double onUranus() {
        return onEarth() / 84.016846;
    }

    public double onNeptune() {
        return onEarth() / 164.79132;
    }
}
