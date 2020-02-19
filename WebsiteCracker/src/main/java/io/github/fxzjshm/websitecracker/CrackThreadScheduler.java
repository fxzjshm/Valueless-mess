package io.github.fxzjshm.websitecracker;

public class CrackThreadScheduler {
    final String t, ua, unf, pwf;

    public CrackThreadScheduler(String target, String userAgent, String usernameField, String passwordField) {
        t = target;
        ua = userAgent;
        unf = usernameField;
        pwf = passwordField;
    }
}
