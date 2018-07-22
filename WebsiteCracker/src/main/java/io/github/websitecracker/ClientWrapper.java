package io.github.websitecracker;

import java.net.MalformedURLException;

public abstract class ClientWrapper {
    final String t, ua, unf, pwf;

    public ClientWrapper(String target, String userAgent, String usernameField, String passwordField)
            throws MalformedURLException {
        t = target;
        ua = userAgent;
        unf = usernameField;
        pwf = passwordField;
    }

    public abstract void start();
}
