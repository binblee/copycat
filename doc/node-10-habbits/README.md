# 10 Habbits of Node Hacker

From [10 Habits of a Happy Node Hacker (2016)](http://blog.heroku.com/archives/2015/11/10/node-habits-2016)

### Create new project with npm init

```javascript
npm init --yes
```
You will not be asked questions if you run the command with --yes option.

Specify an 'engine' key in package.json if you want to lock down node version.

```
"engines": {
  "node": "5.0.0"
}
```

### Save dependencies when install package

```
npm install foobar --save --save-exact
```

Or you can set these options in ~/.npmrc to update your defaults.

```
npm config set save=true
npm config set save-exact=true
```


### ES6

### Stick with lowercase

### Clustering

### Be environmental aware

### Avoid garbage

### Hook things up

### Use .gitignore
