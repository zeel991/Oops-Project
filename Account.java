public abstract class Account {
    protected String name;
    protected String id;

    public Account(String name, String id) {
        this.name = name;
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }

    public abstract void viewDashboard();
}
