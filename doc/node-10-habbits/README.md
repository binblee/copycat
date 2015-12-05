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

By default, npm does not save installed package dependencies to package.json.

With option --save, npm installs the packages with a leading carat(^), putting
your modules at risk of drifting to different versions.

One solution is installing packages like this:

```
npm install foobar --save --save-exact
```

Or you can set these options in ~/.npmrc to update your defaults.

```
npm config set save=true
npm config set save-exact=true
```

### ES6

Node 4+ has many nice ES6 features, try them out.

### Stick with lowercase

Always use lowercase.

### Clustering

To take advantage of multiple cores and memory beyond 1.5GB,
[bake cluster](https://nodejs.org/api/cluster.html) support into your app.

Try [forky](https://www.npmjs.com/package/forky) or
[throng](https://www.npmjs.com/package/throng) for cluster management.

### Be environmental aware

Install foreman
```bash
npm install foreman --save
```

Create a Procfile to specify your app's types.
```
web: bin/web
```

Start your app with nf binary:
```
"scripts":{
  "start": "nf start"
}
```

To provide a local development environment, create a .gitignore'd .env file,
which will be loaded by node-foreman:
```
DATABASE_URL='postgres://localhost/foobar'
HTTP_TIMEOUT=10000
```

Now, a single command (npm start) will spin up both a web process and a worker
process in that environment.

### Avoid garbage

To gain more control over your app's garbage collector, you can provide flags
to V8 in your Procfile:
```
web: node --optimize_for_size --max_old_space_size=920 --gc_interval=100 server.js
```

### Hook things up

Make use of npm's [lifecycle scripts](https://docs.npmjs.com/misc/scripts)

### Use .gitignore

```
wget -O .gitignore https://raw.githubusercontent.com/github/gitignore/master/Node.gitignore
```
